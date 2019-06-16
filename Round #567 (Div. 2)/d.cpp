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
#define N 500010
ll n, m, q;
ll num[N];
ll cnt[N], sum[N], now[N];
unordered_map<int, vi> mm;

ll lowbit(ll x) {return x & -x;}

void add(ll ind, ll offset) {
    while (ind < N) {
        now[ind] += offset;
        ind += lowbit(ind);
    }
}

ll sumup(ll ind) {
    ll res = 0;
    while (ind) {
        res += now[ind];
        ind -= lowbit(ind);
    }
    return res;
}

// year, query index
vector<pair<ll, int>> qq;
vector<int> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef ZYC_LOCAL
    freopen("input.txt", "rt", stdin);
#endif
    cin >> n >> m >> q;
    int a;
    memset(num, 0, sizeof(num));
    memset(sum, 0, sizeof(sum));
    memset(now, 0, sizeof(now));
    go(i, 1, n) {
        cin >> a;
        num[a]++;
    }

    ll ma = 0;
    go(i, 1, m) {
        ma = max(ma, num[i]);
        cnt[num[i]]++;
        sum[num[i]] += num[i];
        mm[num[i]].pb(i);
    }

    go(i, 1, N - 1) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }

    res.assign(q + 1, -1);
    ll k;
    go(i, 1, q) {
        cin >> k;
        qq.emplace_back(k, i);
    }
    sort(all(qq));

    int pre = 0;
    for (auto i : mm[pre]) add(i, 1);
    for (int i = 0; i < q; ++i) {
        ll year = qq[i].fi;
        ll diff = year - n - 1;
        int ind = qq[i].se;
        ll l = 0, r = ma;
        while (l < r) {
            ll mid = r - (r - l) / 2;
            ll tmp = cnt[mid] * mid - sum[mid];
            if (tmp <= diff) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l == ma) {
            while (i < q) {
                res[qq[i].se] = qq[i].fi % m;
                if (!res[qq[i].se]) res[qq[i].se] = m;
                ++i;
            }
            break;
        } else {
            while (pre < l) {
                ++pre;
                for (auto t : mm[pre]) add(t, 1);
            }
            ll tmp = cnt[l] * l - sum[l];
            ll remain = year - n - tmp;
            int lind = 1, rind = m;
            while (lind < rind) {
                int mind = lind + (rind - lind) / 2;
                if (sumup(mind) < remain) {
                    lind = mind + 1;
                } else {
                    rind = mind;
                }
            }
            res[ind] = lind;
        }
    }

    go(i, 1, q) cout << res[i] << endl;

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
