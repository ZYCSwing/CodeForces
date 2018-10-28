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
template <class T> ostream &operator <<(ostream &os, set<T> s) {
    os << "["; for (auto ss : s) os << ss << ","; return os << "]";
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

/******************************** template ********************************/
#define N 100005
int n, m, op, l, r;
ll seed, vm, x, y, a[N];

ll rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13) % MOD;
    return ret;
}

struct Node {
    int left, right;
    mutable ll val;
    Node(int le, int ri = -1, ll v = 0) : left(le), right(ri), val(v) {}
    bool operator < (const Node& o) const {
        return left < o.left;
    }
};

set<Node> s;

auto split(int x) {
    auto it = s.lower_bound(Node(x));
    if (it != s.end() && it->left == x) return it;
    --it;
    if (it->right < x) return s.end();
    int l = it->left, r = it->right;
    ll v = it->val;
    s.erase(it);
    s.insert(Node(l, x - 1, v));
    return s.insert(Node(x, r, v)).fi;
}

ll power_mod(ll base, int exp, int mod = MOD) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef ZYC_LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> seed >> vm;
    go(i, 1, n) {
        a[i] = (rnd() % vm) + 1;
        if (a[i] != a[i - 1]) {
            s.insert(Node(l, i - 1, a[i - 1]));
            l = i;
        }
    }
    s.insert(Node(l, n, a[n]));

    go(i, 1, m) {
        op = (rnd() % 4) + 1;
        l = (rnd() % n) + 1;
        r = (rnd() % n) + 1;

        if (l > r) swap(l, r);
        if (op == 3) {
            x = (rnd() % (r - l + 1)) + 1;
        } else {
            x = (rnd() % vm) + 1;
        }

        if (op == 4) {
            y = (rnd() % vm) + 1;
        }

        auto itl = split(l), itr = split(r + 1);
        if (op == 1) {
            for (; itl != itr; ++itl) {
                itl->val += x;
            }
        } else if (op == 2) {
            s.erase(itl, itr);
            s.insert(Node(l, r, x));
        } else if (op == 3) {
            vector<pair<ll, int>> vec;
            for (; itl != itr; ++itl) {
                vec.pb({itl->val, itl->right - itl->left + 1});
            }
            sort(all(vec));

            for (auto pr : vec) {
                if (x <= pr.se) {
                    cout << pr.fi << endl;
                    break;
                }
                x -= pr.se;
            }
        } else {
            ll sum = 0;
            for (; itl != itr; ++itl) {
                sum += (ll)(itl->right - itl->left + 1) % y * power_mod(itl->val % y, x, y) % y;
                sum %= y;
            }
            cout << sum << endl;
        }
    }

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
