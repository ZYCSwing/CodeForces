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
int a, b, f, k;

vector<ll> foo;

int main() {
    cin >> a >> b >> f >> k;

    if (k == 1) {
        if (f > b || a - f > b) {
            cout << -1;
        } else if (a <= b) {
            cout << 0;
        } else {
            cout << 1;
        }
    } else if (k == 2) {
        if (f > b || 2 * (a - f) > b) {
            cout << -1;
        } else if (2 * a <= b) {
            cout << 0;
        } else if (2 * a - f > b) {
            cout << 2;
        } else {
            cout << 1;
        }
    } else {//k >= 3
        if (2 * f > b || 2 * (a - f) > b) {
            cout << -1;
        } else {
            foo.pb(0);
            for (int i = 0; i < k; ++i) {
                if (i % 2 == 0) {
                    foo.pb(1LL * i * a + f);
                } else {
                    foo.pb(1LL * (i + 1) * a - f);
                }
            }

            ll remain = b, res = 0;
            for (int i = 1; i <= k; ++i) {
                remain -= foo[i] - foo[i - 1];
                if (remain < 0) {
                    ++res;
                    remain = (ll)b - (foo[i] - foo[i - 1]);
                }
            }
            remain -= 1LL * k * a - foo.back();
            if (remain < 0) ++res;
            cout << res;
        }
    }

    return 0;
}