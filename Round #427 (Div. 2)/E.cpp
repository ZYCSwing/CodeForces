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
/**
 * 先按位找出两个特殊值不同的位置，然后挑其中一个不同位，用二分查找找出特殊值的下标，
 * 最后根据两个特殊值每个位上相同与否即可求出另一个值的下标
 */
#define MAXN 200010
int n, x, y;
int cnt = 0;

int a, b;

void findOne(vector<int>& cand) {
    if (cand.size() == 1) {
        a = b = cand[0];
        return;
    } else {
        int mid = cand.size() / 2;
        vector<int> front(cand.begin(), cand.begin() + mid), back(cand.begin() + mid, cand.end());
        int expect = mid % 2 ? y : x ^ y;
        printf("? %d ", mid);

        ++cnt;

        for (int i = 0; i < mid; ++i) {
            printf("%d%c", front[i], " \n"[i == mid - 1]);
        }
        int res;
        cin >> res;
        if (res == expect) {
            findOne(front);
        } else {
            findOne(back);
        }
    }
}

int main() {
    cin >> n >> x >> y;

    bool diff[10];
    memset(diff, 0, sizeof(diff));

    for (int i = 0; i < 10; ++i) {
        if ((1 << i) > n) break;
        vector<int> cand, another;
        for (int j = 1; j <= n; ++j) {
            if ((j & (1 << i)) > 0) {
                cand.pb(j);
            } else {
                another.pb(j);
            }
        }
        int expect = cand.size() % 2 ? y : x ^ y;
        printf("? %d ", (int)cand.size());

        ++cnt;

        for (int j = 0; j < cand.size(); ++j) {
            printf("%d%c", cand[j], " \n"[j == cand.size() - 1]);
        }
        int res;
        cin >> res;
        if (res == expect) {
            diff[i] = true;
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (diff[i]) {
            vector<int> cand, another;
            for (int j = 1; j <= n; ++j) {
                if ((j & (1 << i)) > 0) {
                    cand.pb(j);
                } else {
                    another.pb(j);
                }
            }
            findOne(cand.size() <= another.size() ? cand : another);
            break;
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (diff[i]) {
            b ^= (1 << i);
        }
    }

    if (a > b) swap(a, b);

    printf("! %d %d", a, b);

//    cout << endl << cnt << endl;

    return 0;
}