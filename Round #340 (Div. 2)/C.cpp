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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

#define MAXN 2010
int n;
ll x[2], y[2];
pair<ll, ll> flower[MAXN];

ll dist(ll x, ll y, ll x0, ll y0) {
    return (x - x0) * (x - x0) + (y - y0) * (y - y0);
}

bool check(ll r) {
    ll r1, r2;
    unordered_set<int> ss;
    for (int i = 0; i < n; ++i) {
        ss.insert(i);
    }
    r1 = r, r2 = 0;
    while (1) {
        unordered_set<int> foo, bar;
        bool flag = true;
        for (int f : ss) {
            if (dist(flower[f].fi, flower[f].se, x[0], y[0]) > r1) {
                flag = false;
                r2 = max(r2, dist(flower[f].fi, flower[f].se, x[1], y[1]));
            } else {
                foo.insert(f);
            }
        }
        if (flag) return true;
        r1 = r - r2;
        if (r1 < 0) break;
        ss = foo;
    }
    return false;
}

int main() {
    cin >> n >> x[0] >> y[0] >> x[1] >> y[1];
    for (int i = 0; i < n; ++i) {
        cin >> flower[i].fi >> flower[i].se;
    }

    ll l = 0, r = (ll)1e18;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l;

    return 0;
}