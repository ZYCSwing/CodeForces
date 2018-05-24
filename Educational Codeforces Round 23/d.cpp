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
#define N ((int)1e6+5)
int n;
int a[N], pa[N], l[N], r[N];
vi p[N];
ll lessorequal[N], moreorequal[N];
ll cur;

void init() {
    cur = 0;
    go(i, 0, N - 1) pa[i] = l[i] = r[i] = i;
}

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        ll len1 = r[x] - l[x] + 1, len2 = r[y] - l[y] + 1;
        cur -= len1 * (len1 + 1) / 2 + len2 * (len2 + 1) / 2;
        if (x > y) swap(x, y);
        pa[y] = x;
        r[x] = r[y];
        ll len = r[x] - l[x] + 1;
        cur += len * (len + 1) / 2;
        return true;
    }
    return false;
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
    cin >> n;
    go(i, 0, n - 1) {
        cin >> a[i];
        p[a[i]].pb(i);
    }

    init();
    go(i, 1, N - 1) {
        cur += p[i].size();
        for (int pos : p[i]) {
            if (pos && a[pos - 1] <= a[pos]) {
                merge(pos - 1, pos);
            }
            if (pos < n - 1 && a[pos + 1] <= a[pos]) {
                merge(pos, pos + 1);
            }
        }
        lessorequal[i] = cur;
    }

    init();
    gorev(i, N - 2, 1) {
        cur += p[i].size();
        for (int pos : p[i]) {
            if (pos && a[pos - 1] >= a[pos]) {
                merge(pos - 1, pos);
            }
            if (pos < n - 1 && a[pos + 1] >= a[pos]) {
                merge(pos, pos + 1);
            }
        }
        moreorequal[i] = cur;
    }

    ll res = 0;
    go(i, 1, N - 1) {
        ll ma = lessorequal[i] - lessorequal[i - 1];
        ll mi = moreorequal[i] - (i < N - 1 ? moreorequal[i + 1] : 0);
        res += (ma - mi) * i;
    }
    cout << res;

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}

/*
 * 需要关注的是每个值作为区间最大（小）值出现的次数，而不一定非要求出特定区间的最值
 * 所以可以用 dsu 的思路，逐步地计算得到小于等于（大于等于）某个值的区间数目，再做
 * 个差值就得到了特定值作为最值出现在的区间数目。最大值加到结果中，最小值从结果中减
 * 去即可。
 */