#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)
#define EPS 1e-8
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const ll mod = (ll)1e9 + 7;

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

inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

inline void write(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

inline double dbread()
{
    double X=0,Y=1.0; int w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=X*10+(ch^48),ch=getchar();
    ch=getchar();//读入小数点
    while(isdigit(ch)) X+=(Y/=10)*(ch^48),ch=getchar();
    return w?-X:X;
}

/*************************
 ******* template ********
 ************************/
#define N 100010
ll n, m, k;
ll s, t, d, w;

struct event {
    ll t, v, d, w;
};

// w, d
bool cmp(pll p1, pll p2) {
    return p1.fi > p2.fi || (p1.fi == p2.fi && p1.se > p2.se);
}

bool(*fn_pt)(pll, pll) = cmp;

map<pll, int, bool(*)(pll, pll)> mm(fn_pt);
ll dp[N][210];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef ZYC_LOCAL
    freopen("input.txt", "rt", stdin);
#endif
    cin >> n >> m >> k;

    auto cmp1 = [](event e1, event e2) {
        return e1.t < e2.t;
    };

    priority_queue<event, vector<event>, decltype(cmp1)> pq(cmp1);

    go(i, 1, k) {
        cin >> s >> t >> d >> w;
        pq.push({s - 1, -1, d, w});
        pq.push({t, 1, d, w});
    }

    for (int i = (int)1e5; i >= 0; --i) {
        while (!pq.empty() && pq.top().t == i) {
            auto item = pq.top();
            pq.pop();
            if (item.v > 0) {
                mm[{item.w, item.d}]++;
            } else {
                if (!--mm[{item.w, item.d}]) {
                    mm.erase({item.w, item.d});
                }
            }
        }
        for (int j = 0; j <= m; ++j) {
            if (mm.empty()) {
                dp[i][j] = dp[i + 1][j];
            } else if (j) {
                auto& item = (*mm.begin()).fi;
                dp[i][j] = min(dp[i + 1][j - 1], dp[item.se + 1][j] + item.fi);
            } else {
                auto& item = (*mm.begin()).fi;
                dp[i][j] = dp[item.se + 1][j] + item.fi;
            }
        }
    }

    cout << dp[0][m];

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
