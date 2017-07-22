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
#define MAXN 1010
string s, t;
ll question = 0, cnts[26], cntt[26];

bool check(int x) {
    ll tmp = 0;
    for (int i = 0; i < 26; ++i) {
        if (x * cntt[i] > cnts[i]) {
            tmp += x * cntt[i] - cnts[i];
            if (tmp > question) return false;
        }
    }
    return true;
}

int main() {
    memset(cnts, 0, sizeof(cnts));
    memset(cntt, 0, sizeof(cntt));
    cin >> s >> t;
    if (s.length() < t.length()) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '?') s[i] = 'a';
        }
        cout << s;
        return 0;
    }
    for (char ch : s) {
        if (ch == '?') {
            ++question;
        } else {
            ++cnts[ch - 'a'];
        }
    }
    for (char ch : t) {
        ++cntt[ch - 'a'];
    }

    int l = 0, r = s.length() / t.length();
    while (l < r) {
        int mid = r - (r - l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    int index = 0;

    for (int i = 0; i < 26; ++i) {
        int diff = l * cntt[i] - cnts[i];
        if (diff > 0) {
            while (diff) {
                while (s[index] != '?') {
                    ++index;
                }
                s[index++] = 'a' + i;
                --diff;
            }
            question -= diff;
        }
    }

    while (index < s.length()) {
        if (s[index] == '?') s[index] = 'a';
        ++index;
    }

    cout << s;

    return 0;
}