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
#define MAXN 200010
int n;
int a[MAXN];
set<int> indexs[MAXN];
vector<int> dupPos;
vector<int> miss;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        indexs[a[i]].insert(i);
    }

    for (int i = 0; i < n; ++i) {
        if (indexs[a[i]].size() > 1) {
            dupPos.pb(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (indexs[i].empty()) miss.pb(i);
    }

    int p = 0;//point to miss
    for (int pos : dupPos) {
        if (p == miss.size()) break;
        if (indexs[a[pos]].size() == 1) continue;
        if (a[pos] > miss[p]) {
            indexs[a[pos]].erase(pos);
            a[pos] = miss[p];
            ++p;
        } else {
            if (pos != *indexs[a[pos]].begin()) {
                indexs[a[pos]].erase(pos);
                a[pos] = miss[p];
                ++p;
            }
        }
    }

    cout << miss.size() << endl;
    for (int i = 0; i < n; ++i) {
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }

    return 0;
}