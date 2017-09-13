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
int b, q, l, m;
unordered_set<int> ss;

int main() {
    cin >> b >> q >> l >> m;
    for (int i = 0; i < m; ++i) {
        int a;
        scanf("%d", &a);
        ss.insert(a);
    }

    if (b == 0) {
        if (ss.find(0) == ss.end()) {
            cout << "inf";
        } else {
            cout << 0;
        }
        return 0;
    }

    if (q == 0) {
        if (abs(b) <= l) {
            if (ss.find(b) == ss.end()) {
                if (ss.find(0) == ss.end()) {
                    cout << "inf";
                } else {
                    cout << 1;
                }
            } else {
                if (ss.find(0) == ss.end()) {
                    cout << "inf";
                } else {
                    cout << 0;
                }
            }
        } else {
            cout << 0;
        }
        return 0;
    }

    if (abs(q) == 1) {
        if (abs(b) <= l) {
            if (q == 1) {
                if (ss.find(b) == ss.end()) {
                    cout << "inf";
                } else {
                    cout << 0;
                }
            } else {
                if (ss.find(b) == ss.end() || ss.find(-b) == ss.end()) {
                    cout << "inf";
                } else {
                    cout << 0;
                }
            }
        } else {
            cout << 0;
        }
        return 0;
    }

    int res = 0;
    ll tmp = b;
    while (abs(tmp) <= l) {
        if (ss.find(tmp) == ss.end()) ++res;
        tmp *= q;
    }
    cout << res;

    return 0;
}