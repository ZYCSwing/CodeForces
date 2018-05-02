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
#include <cstdio>
#include <ctype.h>
#include <time.h>
using namespace std;

#define PI acos(-1.0)
#define EPS 1e-8
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
#define go(i, a, b) for(int i = a; i <= b; ++i)
#define gorev(i, a, b) for(int i = a; i >= b; --i)

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
    return os << "(" << P.fi << "," << P.se << ")";
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
    os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, map<L, R> M){
    os << "["; for (auto pr: M) os << pr.fi << "->" << pr.se << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, unordered_map<L, R> M){
    os << "["; for (auto pr: M) os << pr.fi << "->" << pr.se << ","; return os << "]";
}

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

vector<int> extendGcd(int a, int b) {
    if (b == 0) {
        return {1, 0, a};
    } else {
        vector<int> tmp = extendGcd(b, a % b);
        return {tmp[1], tmp[0] - (a / b) * tmp[1], tmp[2]};
    }
}

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

/******************************** template ********************************/
#define N 200010
ll n, a, b;
ll x[N], vx[N], vy[N];
ll fix = 0, cnt1 = 0;
map<pair<ll, ll>, ll> foo1;
unordered_map<ll, map<pair<ll, ll>, ll>> foo2;
unordered_map<ll, ll> cnt2;

ll gcd(ll p, ll q) {
    if (q == 0) return p;
    return gcd(q, p % q);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef ZYC_LOCAL
    freopen("input.txt", "rt", stdin);
#endif
    cin >> n >> a >> b;
    go(i, 1, n) {
        cin >> x[i] >> vx[i] >> vy[i];
        if (vx[i] == 0 && vy[i] == 0) {
            fix++;
        } else {
            ll tmp = vy[i] - a * vx[i];
            if (tmp == 0) {
                cnt1++;
                foo1[{vx[i], vy[i]}]++;
            } else {
                if (vx[i] < 0) {
                    vx[i] = -vx[i];
                    vy[i] = -vy[i];
                } else if (vx[i] == 0) {
                    vy[i] = abs(vy[i]);
                }
                ll bar = gcd(vx[i], abs(vy[i]));
                vx[i] /= bar;
                vy[i] /= bar;
                foo2[tmp][{vx[i], vy[i]}]++;
                cnt2[tmp]++;
            }
        }
    }

    ll res = 0;
    for (auto item : foo1) {
        res += 2LL * item.se * fix;
        res += item.se * (cnt1 - item.se);
    }
    for (auto item : foo2) {
        for (auto pr : item.se) {
            res += pr.se * (cnt2[item.fi] - pr.se);
        }
    }
    cout << res;

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
