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
#define MAXN 110
int n;
struct cube{
    double x1, y1, x2, y2;
    double midx, midy;
    double w;
} c[MAXN];

bool check(int index) {
    double xx = c[index].midx, yy = c[index].midy;
    double ww = c[index].w;
    for (int i = index - 1; i >= 0; --i) {
        if ((xx < c[i].x1 && xx < c[i].x2) ||
            (xx > c[i].x1 && xx > c[i].x2) ||
            (yy < c[i].y1 && yy < c[i].y2) ||
            (yy > c[i].y1 && yy > c[i].y2)) {
            return false;
        }
        xx = (ww * xx + c[i].w * c[i].midx) / (ww + c[i].w);
        yy = (ww * yy + c[i].w * c[i].midy) / (ww + c[i].w);
        ww += c[i].w;
    }
    return true;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> c[i].x1 >> c[i].y1 >> c[i].x2 >> c[i].y2;
        c[i].midx = (c[i].x1 + c[i].x2) / 2;
        c[i].midy = (c[i].y1 + c[i].y2) / 2;
        c[i].w = pow(abs(c[i].x1 - c[i].x2), 3);
    }

    int i;
    for (i = 0; i < n; ++i) {
        if (!check(i)) {
            break;
        }
    }
    cout << i;

    return 0;
}