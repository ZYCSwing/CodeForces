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

//ll myPow(ll base, ll exp) {
//    ll res = 1;
//    while (exp) {
//        if (exp & 1) {
//            res = res * base % mod;
//        }
//        base = base * base % mod;
//        exp >>= 1;
//    }
//    return res;
//}

ll n;
vector<ll> foo, nums;

int main() {
    cin >> n;
    foo.resize(n);
    nums.resize(n);
    foo[0] = 1;
    for (int i = 1; i < n; ++i) {
        foo[i] = foo[i - 1] << 1;
        if (foo[i] >= mod) foo[i] %= mod;
    }
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res = (res + nums[i] * (foo[i] - foo[n - i - 1]) % mod) % mod;
    }
    if (res < 0) res += mod;
    cout << res;

    return 0;
}