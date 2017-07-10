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
    vector<vector<int>> data;
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
int n, c, d;
struct fountain {
    int b, p;
};
fountain f[2][MAXN];
int cnt0 = 0, cnt1 = 0;

bool cmp(fountain f1, fountain f2) {
    return f1.p < f2.p;
}

int foo[MAXN];

int lowbit(int x) {return x & -x;}

void update(int x, int v) {
    while (x < MAXN && v > foo[x]) {
        foo[x] = v;
        x += lowbit(x);
    }
}

int getMax(int x) {
    int res = 0;
    while (x) {
        res = max(res, foo[x]);
        x -= lowbit(x);
    }
    return res;
}

int solve(fountain* ff, int sz, int upper) {
    memset(foo, 0, sizeof(foo));
    int res = 0;
    for (int i = 0; i < sz; ++i) {
        if (ff[i].p >= upper) continue;
        int tmp = getMax(upper - ff[i].p);
        if (tmp > 0) res = max(res, tmp + ff[i].b);
        update(ff[i].p, ff[i].b);
    }
    return res;
}

int main() {
    cin >> n >> c >> d;
    for (int i = 0; i < n; ++i) {
        int bb, pp;
        char type;
        cin >> bb >> pp >> type;
        if (type == 'C') {
            f[0][cnt0].b = bb;
            f[0][cnt0++].p = pp;
        } else {
            f[1][cnt1].b = bb;
            f[1][cnt1++].p = pp;
        }
    }

    int res = 0;
    res = max(solve(f[0], cnt0, c), solve(f[1], cnt1, d));

    sort(f[0], f[0] + cnt0, cmp);
    sort(f[1], f[1] + cnt1, cmp);
    int x = 0, y = 0;
    for (int i = 0; i < cnt0 && f[0][i].p <= c; ++i) {
        x = max(x, f[0][i].b);
    }
    for (int i = 0; i < cnt1 && f[1][i].p <= d; ++i) {
        y = max(y, f[1][i].b);
    }
    if (x > 0 && y > 0) res = max(res, x + y);

    cout << res;

    return 0;
}