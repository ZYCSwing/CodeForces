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
#define MAXN 1010
int n;
ld x[MAXN], y[MAXN];

ld dist(int a, int b) {
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

ld solve(int cur) {
    ld a = dist(cur - 1, cur), b = dist(cur, cur + 1), c = dist(cur - 1, cur + 1);
    ld p = (a + b + c) / 2;
    ld s = sqrt(p * (p - a) * (p - b) * (p - c));
    return 2 * s / max(a, max(b, c));
}

//double cross(int a, int b, int c) {
//    double dx1 = x[b] - x[a], dy1 = y[b] - y[a];
//    double dx2 = x[c] - x[a], dy2 = y[c] - y[a];
//    return abs(dx1 * dy2 - dx2 * dy1);
//}
//
//double solve(int cur) {
//    double a = dist(cur - 1, cur), b = dist(cur, cur + 1), c = dist(cur - 1, cur + 1);
//    double area = cross(cur - 1, cur, cur + 1);
//    return area / max(a, max(b, c));
//}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%Lf%Lf", x + i, y + i);
    }

    ld res = 1e30;

    for (int j = 0; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
            res = min(res, dist(j, k));
        }
    }

    x[n] = x[0], x[n + 1] = x[1];
    y[n] = y[0], y[n + 1] = y[1];

    for (int i = 1; i <= n; ++i) {
        res = min(res, solve(i));
    }

    printf("%.8Lf", res / 2);

    return 0;
}