#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <ctype.h>
using namespace std;

#define PI acos(-1.0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

#define eps 1e-8
#define mod 1000000007

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

/******************************** template ********************************/
#define MAXN 100010
#define MAXK 2000010
int n, m, k;

struct ticket {
    int day;
    int from;
    int to;
    int cost;
} t[MAXN];

vector<ticket> got, backt;
ll godp[MAXK], backdp[MAXK];

bool cmp(ticket& t1, ticket& t2) {
    return t1.day < t2.day;
}

bool cmp1(ticket& t1, ticket& t2) {
    return t1.day > t2.day;
}

int main() {
    cin >> n >> m >> k;
    int upperDate = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &t[i].day, &t[i].from, &t[i].to, &t[i].cost);
        upperDate = max(upperDate, t[i].day);
        if (t[i].from == 0) {
            backt.push_back(t[i]);
        } else {
            got.push_back(t[i]);
        }
    }

    sort(all(got), cmp);//early to late
    sort(all(backt), cmp1);//late to early

    memset(godp, -1, sizeof(godp));
    unordered_map<int, int> foo;
    int index = 0;
    ll sum = 0;
    for (int date = 1; date <= upperDate; ++date) {
        while (index < got.size() && got[index].day <= date) {
            if (foo.find(got[index].from) == foo.end()) {
                foo[got[index].from] = got[index].cost;
                sum += got[index].cost;
            } else {
                if (foo[got[index].from] > got[index].cost) {
                    sum -= foo[got[index].from] - got[index].cost;
                    foo[got[index].from] = got[index].cost;
                }
            }
            ++index;
        }
        if (foo.size() == n) {
            godp[date] = sum;
        }
    }

    memset(backdp, -1, sizeof(backdp));
    foo.clear();
    index = 0;
    sum = 0;
    for (int date = upperDate; date >= 1; --date) {
        while (index < backt.size() && backt[index].day >= date) {
            if (foo.find(backt[index].to) == foo.end()) {
                foo[backt[index].to] = backt[index].cost;
                sum += backt[index].cost;
            } else {
                if (foo[backt[index].to] > backt[index].cost) {
                    sum -= foo[backt[index].to] - backt[index].cost;
                    foo[backt[index].to] = backt[index].cost;
                }
            }
            ++index;
        }
        if (foo.size() == n) {
            backdp[date] = sum;
        }
    }

    ll res = -1;
    for (int date = 2; date + k <= upperDate; ++date) {
        if (godp[date - 1] != -1 && backdp[date + k] != -1) {
            if (res == -1) {
                res = godp[date - 1] + backdp[date + k];
            } else {
                res = min(res, godp[date - 1] + backdp[date + k]);
            }
        }
    }

    if (res == -1) {
        cout << -1;
    } else {
        cout << res;
    }

    return 0;
}