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
#include <random>
#include <functional>
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

mt19937_64 mt(time(0));

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

inline char get(void) {
    static char buf[100000], *S = buf, *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}

template<class T> inline void read(T &x) {
    static char c; x = 0; int sgn = 0;
    for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
    for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
    if (sgn) x = -x;
}

/*************************
 ******* template ********
 ************************/
#define N 400010
int n, d, k;
vi e[N];
int level[N];
vector<pii> ee;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef ZYC_LOCAL
    freopen("input.txt", "rt", stdin);
#endif
    cin >> n >> d >> k;

    if (d > n - 1) {
        cout << "NO";
        return 0;
    }
    if (k == 1) {
        if (n > 2 || n == 1) {
            cout << "NO";
        } else {
            if (d != 1) {
                cout << "NO";
            } else {
                cout << "YES" << endl;
                cout << "1 2";
            }
        }
        return 0;
    } else if (k == 2) {
        if (n != d + 1) {
            cout << "NO";
        } else {
            cout << "YES" << endl;
            go(i, 1, n - 1) cout << i << " " << i + 1 << endl;
        }
        return 0;
    } else {
        memset(level, -1, sizeof(level));
        if (d % 2) {
            int dd = (d - 1) / 2;
            ll foo = 1LL * n * (k - 2) + 2;
            ll bar = 2;
            bool ok = false;
            for (int i = 0; i <= dd; ++i) {
                bar *= k - 1;
                if (bar >= foo) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "NO";
                return 0;
            }

            e[1].pb(2);
            e[2].pb(1);
            ee.pb({1, 2});
            level[1] = level[2] = 0;
            int pre = 1;
            for (int i = 3; i <= dd + 2; ++i) {
                e[pre].pb(i);
                e[i].pb(pre);
                ee.pb({pre, i});
                level[i] = level[pre] + 1;
                pre = i;
            }
            pre = 2;
            for (int i = dd + 3; i <= 2 * dd + 2; ++i) {
                e[pre].pb(i);
                e[i].pb(pre);
                ee.pb({pre, i});
                level[i] = level[pre] + 1;
                pre = i;
            }
            int next = 2 * dd + 3;
            for (int pa = 1; pa <= n && next <= n; ++pa) {
                if (level[pa] == dd) continue;
                while (e[pa].size() < k && next <= n) {
                    e[pa].pb(next);
                    e[next].pb(pa);
                    ee.pb({pa, next});
                    level[next] = level[pa] + 1;
                    ++next;
                }
            }
            cout << "YES" << endl;
            for (auto pr : ee) {
                cout << pr.fi << " " << pr.se << endl;
            }

        } else {
            ll tot = 1, pre = 1;
            bool ok = false;
            for (int i = 1; i <= d / 2; ++i) {
                if (pre == 1) {
                    tot += k;
                    pre = k;
                } else {
                    pre *= k - 1;
                    tot += pre;
                }
                if (tot >= n) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "NO";
                return 0;
            }

            int dd = d / 2, pa = 1;
            level[1] = 0;
            for (int i = 2; i <= dd + 1; ++i) {
                e[pa].pb(i);
                e[i].pb(pa);
                ee.pb({pa, i});
                level[i] = level[pa] + 1;
                pa = i;
            }
            pa = 1;
            for (int i = dd + 2; i <= 2 * dd + 1; ++i) {
                e[pa].pb(i);
                e[i].pb(pa);
                ee.pb({pa, i});
                level[i] = level[pa] + 1;
                pa = i;
            }

            int next = 2 * dd + 2;
            for (int pa = 1; pa <= n && next <= n; ++pa) {
                if (level[pa] == dd) continue;
                while (e[pa].size() < k && next <= n) {
                    e[pa].pb(next);
                    e[next].pb(pa);
                    ee.pb({pa, next});
                    level[next] = level[pa] + 1;
                    ++next;
                }
            }

            cout << "YES" << endl;
            for (auto pr : ee) {
                cout << pr.fi << " " << pr.se << endl;
            }
        }
    }


#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
