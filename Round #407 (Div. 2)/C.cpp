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
int n;
int a[MAXN];
int b[MAXN];

set<ll> odd, even;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < n - 1; ++i) {
        b[i] = abs(a[i] - a[i + 1]);
    }

    even.insert(0);
    ll sum = 0;
    ll res = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (i % 2 == 0) {
            sum += b[i];
        } else {
            sum -= b[i];
        }
        res = max(res, sum - *even.begin());
        if (!odd.empty()) {
            res = max(res, *odd.rbegin() - sum);
        }
        if (i % 2) {
            even.insert(sum);
        } else {
            odd.insert(sum);
        }
    }

    cout << res;

    return 0;
}