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

// 扩展欧几里得算法 res[1] * a + res[2] * b = res[0] = gcd(a, b)
vector<int> extendGcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    } else {
        vector<int> tmp = extendGcd(b, a % b);
        return {tmp[0], tmp[2], tmp[1] - (a / b) * tmp[2]};
    }
}

// 带模快速幂
ll myPow(ll base, int exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// 求逆元
ll inv(ll a) {
    return myPow(a, mod - 2);
}

#define MAXFAC 100010

ll fac[MAXFAC];

void initFac() {
    fac[0] = 1;
    for (int i = 1; i < MAXFAC; ++i) {
        fac[i] = i * fac[i - 1] % mod;
    }
}

ll Combine(ll a, ll b) {
    return (fac[a] * inv(fac[b]) % mod) * inv(fac[a - b]) % mod;
}

/******************************** template ********************************/
int n, m;
string s, t;

vector<int> solve(int start) {
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i + start]) res.push_back(i + 1);
    }
    return res;
}

int main() {
    cin >> n >> m;
    cin >> s >> t;

    int sz = n + 1;
    vector<int> res;
    for (int i = 0; i <= m - n; ++i) {
        vector<int> tmp = solve(i);
        if (tmp.size() < sz) {
            sz = tmp.size();
            res = tmp;
        }
    }

    cout << sz << endl;
    for (int i = 0; i < sz; ++i) {
        if (i) cout << " ";
        cout << res[i];
    }

    return 0;
}