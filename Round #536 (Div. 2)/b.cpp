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
ll n, m;

struct node {
    ll c;
    ll ind;
};

ll cnt[N], price[N];

node foo[N];
ll t, d;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef ZYC_LOCAL
    freopen("input.txt", "rt", stdin);
#endif
    cin >> n >> m;
    go(i, 1, n) {
        cin >> cnt[i];
        foo[i].ind = i;
    }
    go(i, 1, n) {
        cin >> price[i];
        foo[i].c = price[i];
    }

    auto cmp = [](node n1, node n2) {
        return n1.c > n2.c || (n1.c == n2.c && n1.ind > n2.ind);
    };

    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    go(i, 1, n) pq.push(foo[i]);

    while (m--) {
        cin >> t >> d;
        ll res = 0;
        if (d <= cnt[t]) {
            cnt[t] -= d;
            res += d * price[t];
        } else {
            res += cnt[t] * price[t];
            d -= cnt[t];
            cnt[t] = 0;
            while (d > 0 && !pq.empty()) {
                auto item = pq.top();
                if (d <= cnt[item.ind]) {
                    res += d * item.c;
                    cnt[item.ind] -= d;
                    d = 0;
                } else {
                    res += cnt[item.ind] * item.c;
                    d -= cnt[item.ind];
                    cnt[item.ind] = 0;
                    pq.pop();
                }
            }
            if (d > 0) {
                res = 0;
            }
        }
        cout << res << endl;
    }

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}