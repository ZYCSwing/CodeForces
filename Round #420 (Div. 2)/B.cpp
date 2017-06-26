#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <numeric>
#include <cmath>
#include <memory.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<int>> vvi;

#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-8

#define MAXN 100010

ll m, b;
ll res;

int main() {
    cin >> m >> b;
    res = 0;
    for (ll y = 0; y <= b; ++y) {
        ll x = m * (b - y);
        res = max(res, (x + 1) * (y + 1) * (x + y) / 2);
    }
    cout << res;

    return 0;
}