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
#define MAXN 125
int n;
int a[MAXN][5];
int ac[5];

vector<int> getMaxScore(vector<int>& prob, int num) {
    vector<int> res;
    for (int i = 0; i < 5; ++i) {
        if (2 * prob[i] > num) {
            res.pb(500);
        } else if (4 * prob[i] > num) {
            res.pb(1000);
        } else if (8 * prob[i] > num) {
            res.pb(1500);
        } else if (16 * prob[i] > num) {
            res.pb(2000);
        } else if (32 * prob[i] > num) {
            res.pb(2500);
        } else {
            res.pb(3000);
        }
    }

    return res;
}

int calu(vector<int>& scores, int ind) {
    int res = 0;
    for (int i = 0; i < 5; ++i) {
        if (a[ind][i] >= 0) {
            res += scores[i] - scores[i] / 250 * a[ind][i];
        }
    }
    return res;
}

bool ok(int num) {
    vector<int> prob(5);

    for (int i = 0; i < 5; ++i) {
        prob[i] = ac[i];
        if (a[0][i] >= 0 && a[1][i] >= 0 && a[0][i] > a[1][i]) {
            prob[i] += num;
        }
    }

    vector<int> scores = getMaxScore(prob, n + num);
    return calu(scores, 0) > calu(scores, 1);
}

vector<int> upper;

void getUpper(int pid) {
    if (32 * ac[pid] > n) {
        upper.pb(32 * ac[pid] - n);
    }
    if (16 * ac[pid] > n) {
        upper.pb(16 * ac[pid] - n);
    }
    if (8 * ac[pid] > n) {
        upper.pb(8 * ac[pid] - n);
    }
    if (4 * ac[pid] > n) {
        upper.pb(4 * ac[pid] - n);
    }
    if (2 * ac[pid] > n) {
        upper.pb(2 * ac[pid] - n);
    }
}

int main() {
    cin >> n;
    memset(ac, 0, sizeof(ac));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
            if (a[i][j] >= 0) ++ac[j];
        }
    }

    for (int i = 0; i < 5; ++i) {
        if (a[0][i] == -1 && a[1][i] >= 0) {
            getUpper(i);
        }
    }
    sort(all(upper));
    upper.pb(mod + 1);
    upper.resize(distance(upper.begin(), unique(all(upper))));

    int l = 0, r;
    for (int i = 0; i < upper.size(); ++i) {
        r = upper[i];
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (ok(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l != upper[i]) {
            cout << l;
            return 0;
        }
        l = r;
    }

    cout << -1;

    return 0;
}