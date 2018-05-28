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
#include <numeric>
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

/******************************** template ********************************/
#define N 10010
int n, q;
vvi sign(N << 2);

#define L (cur << 1)
#define R ((cur << 1) | 1)

void insert(int cur, int s, int e, int l, int r, int v) {
    if (s > r || e < l) return;

    if (l <= s && e <= r) {
        sign[cur].pb(v);
        return;
    }

    int mid = (s + e) >> 1;
    if (l <= mid) {
        insert(L, s, mid, l, r, v);
    }
    if (r > mid) {
        insert(R, mid + 1, e, l, r, v);
    }
}

bitset<N> res(1);
void solve(int cur, int s, int e, bitset<N> mask) {
    for (int v : sign[cur]) {
        mask |= mask << v;
    }
    if (s == e) {
        res |= mask;
        return;
    }
    int mid = (s + e) >> 1;
    solve(L, s, mid, mask);
    solve(R, mid + 1, e, mask);
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
    cin >> n >> q;
    int l, r, x;
    go(i, 1, q) {
        cin >> l >> r >> x;
        insert(1, 1, N, l, r, x);
    }

    solve(1, 1, N, res);
    vi foo;
    go(i, 1, n) if (res.test(i)) foo.pb(i);
    cout << foo.size() << endl;
    go(i, 0, (int)foo.size() - 1) {
        cout << foo[i] << " \n"[i == (int)foo.size() - 1];
    }

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}

/*
 * 解法一：如上，用 bitset 存每种值作为几个数字的和是否可能存在，用线段树存
 *       当前某些线段上进行的更新，这些更新可以不用马上下推，只需在计算结果
 *       时由上到下的推即可
 * 解法二：对于(l,r,v)，可以用(l,+v),(r+1,-v)来代替，然后从左小到大处理，
 *       对于+，从右往左更新每个数值作为和的组合数量；对于-，从左往右更新
 *       每个数值作为和的组合数量。中间的过程中记录每个值是否可能作为和出现
 *       即可
 */