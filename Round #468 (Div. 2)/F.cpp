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
int n, m;
int cnt[N];
//key:xi value:positions of corresponding points
unordered_map<int, vi> mm;
//amount of smaller element in the left/right
int l[N], r[N];
vi cur;
int dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef ZYC_LOCAL
    freopen("input.txt", "rt", stdin);
#endif
    cin >> n >> m;
    int L, R;
    go(i, 1, n) {
        cin >> L >> R;
        cnt[L]++;
        cnt[R + 1]--;
    }
    go(i, 1, m) {
        cnt[i] += cnt[i - 1];
        mm[cnt[i]].pb(i);
    }

    go(i, 1, m) {
        auto it = upper_bound(all(cur), cnt[i]);
        l[i] = it - cur.begin();
        if (it == cur.end()) {
            cur.pb(cnt[i]);
        } else {
            *it = cnt[i];
        }
    }

    cur.clear();

    gorev(i, m, 1) {
        auto it = upper_bound(all(cur), cnt[i]);
        r[i] = it - cur.begin();
        if (it == cur.end()) {
            cur.pb(cnt[i]);
        } else {
            *it = cnt[i];
        }
    }

    go(i, 0, n) {
        dp[i] = INT_MIN;
    }

    int res = 0;
    go(i, 1, m) {
        dp[cnt[i]] = max(dp[cnt[i]], l[i] - (int)(lower_bound(all(mm[cnt[i]]), i) - mm[cnt[i]].begin()));
        res = max(res, dp[cnt[i]] + r[i] + (int)(lower_bound(all(mm[cnt[i]]), i) - mm[cnt[i]].begin()) + 1);
    }
    cout << res;

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
