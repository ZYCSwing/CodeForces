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

struct Matrix {
    vvi data;
    int r, c;
    Matrix(int row, int col, bool identity = false) : r(row), c(col) {
        data.assign(row, vector<int>(col, 0));
        if (identity) {
            for (int i = 0; i < r; ++i) {
                data[i][i] = 1;
            }
        }
    }
    Matrix operator * (Matrix& other) {
        int m = r, n = c, p = other.c;
        Matrix res(m, p);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < n; ++k) {
                    res.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return res;
    }
};

// 扩展欧几里得算法 res[1] * a + res[2] * b = res[0] = gcd(a, b)
vector<int> extendGcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    } else {
        vector<int> tmp = extendGcd(b, a % b);
        return {tmp[0], tmp[2], tmp[1] - (a / b) * tmp[2]};
    }
}

// 矩阵快速幂
Matrix matrix_power(Matrix base, ll exp) {
    int n = base.r;
    Matrix res(n, n, true);
    while (exp) {
        if (exp & 1) {
            res = res * base;
        }
        base = base * base;
        exp >>= 1;
    }
    return res;
}

// 带模快速幂
ll power_mod(ll base, int exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// 快速幂
ll power(ll base, int exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

// 求逆元
ll inv(ll a) {
    return power_mod(a, mod - 2);
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
#define MAXN 100010

int n;
vector<int> ind[MAXN];
int a[MAXN], cnt[MAXN];

int lowbit(int x) {return x & -x;}

void add(int x, int val) {
    while (x < MAXN) {
        cnt[x] += val;
        x += lowbit(x);
    }
}

int sum(int x) {
    int res = 0;
    while (x) {
        res += cnt[x];
        x -= lowbit(x);
    }
    return res;
}

//(l, r]
int rangeSum(int l, int r) {
    return sum(r) - sum(l);
}

int main() {
    cin >> n;
    int upper = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ind[a[i]].pb(i);
        upper = max(upper, a[i]);
        add(i, 1);
    }

    int pre = 0;
    ll res = 0;
    for (int i = 1; i <= upper; ++i) {
        if (ind[i].empty()) continue;
        auto foo = upper_bound(all(ind[i]), pre);
        if (foo == ind[i].begin()) {
            res += rangeSum(pre, ind[i].back());
            pre = ind[i].back();
        } else {
            res += rangeSum(pre, n) + rangeSum(0, *prev(foo));
            pre = *prev(foo);
        }

        for (int j : ind[i]) {
            add(j, -1);
        }
    }

    cout << res;

    return 0;
}