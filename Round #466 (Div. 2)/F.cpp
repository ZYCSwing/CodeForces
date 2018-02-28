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
#include <time.h>
using namespace std;

#define PI acos(-1.0)
#define EPS 1e-8
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

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

/******************************** template ********************************/
#define N 100010
#define M 200010
struct Query {
    int l;
    int r;
    int t;
    int id;
};

struct Modify {
    int ind;
    int oldV;
    int newV;
};

int n, q, sz, l = 1, r, T;
vi a, b, now;
int Be[N], num[M], cnt[M], ans[M];
vector<Query> qu;
vector<Modify> mo;

int mex() {
    for (int i = 1; i < M; ++i) {
        if (!cnt[i]) return i;
    }
    return 0;
}

bool cmp(Query q1, Query q2) {
    if (Be[q1.l] != Be[q2.l]) {
        return q1.l < q2.l;
    } else if (Be[q1.r] != Be[q2.r]) {
        return q1.r < q2.r;
    } else {
        return q1.t < q2.t;
    }
}

void change(int val, int diff) {
    cnt[num[val]]--;
    num[val] += diff;
    cnt[num[val]]++;
}

void time_move(int id, int val) {
    if (l <= id && id <= r) {
        change(a[id], -1);
        change(val, 1);
    }
    a[id] = val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef ZYC_LOCAL
    freopen("input.txt", "rt", stdin);
#endif
    cin >> n >> q;
    sz = (int)pow(n, 2.0 / 3);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b.pb(a[i]);
        now.pb(a[i]);
        Be[i] = i / sz + 1;
    }
    int type, x, y;
    for (int i = 1; i <= q; ++i) {
        cin >> type >> x >> y;
        if (type == 1) {
            qu.pb({x - 1, y - 1, (int)mo.size(), (int)qu.size()});
        } else {
            mo.pb({x - 1, now[x - 1], y});
            now[x - 1] = y;
            b.pb(y);
        }
    }
    sort(all(b));
    b.resize(distance(b.begin(), unique(all(b))));
    for (int i = 0; i < n; ++i) {
        a[i] = distance(b.begin(), lower_bound(all(b), a[i]));
    }
    for (auto& i : mo) {
        i.oldV = distance(b.begin(), lower_bound(all(b), i.oldV));
        i.newV = distance(b.begin(), lower_bound(all(b), i.newV));
    }

    sort(all(qu), cmp);

    for (auto qqq : qu) {
        while (T < qqq.t) time_move(mo[T].ind, mo[T].newV), ++T;
        while (T > qqq.t) time_move(mo[T - 1].ind, mo[T - 1].oldV), --T;

        while (l < qqq.l) change(a[l], -1), ++l;
        while (l > qqq.l) change(a[l - 1], 1), --l;
        while (r < qqq.r) change(a[r + 1], 1), ++r;
        while (r > qqq.r) change(a[r], -1), --r;

        ans[qqq.id] = mex();
    }

    for (int i = 0; i < (int)qu.size(); ++i) {
        cout << ans[i] << endl;
    }

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
