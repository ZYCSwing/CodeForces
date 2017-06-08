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

ll n, s;
vector<ll> a;

pair<bool, ll> solve(ll k) {
    vector<ll> b = a;
    for (int i = 1; i <= n; ++i) {
        b[i] += k * i;
    }
    sort(b.begin() + 1, b.end());
    ll sum = 0;
    for (int i = 1; i <= k; ++i) {
        sum += b[i];
        if (sum > s) return {false, 0};
    }
    return {true, sum};
};

int main() {
    cin >> n >> s;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = n;
    int cost = 0;
    while (l < r) {
        int mid = r - ((r - l) >> 1);
        auto res = solve(mid);
        if (res.first) {
            l = mid;
            cost = res.second;
        } else {
            r = mid - 1;
        }
    }

    cout << l << " " << cost;

    return 0;
}