#include <bits/stdc++.h>
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
typedef vector<ll> vll;
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
#define N 300010
int n;
ll a[N], b[N], pre[N];

vll odd(N, 0), even(N, 0);
int lowbit(int x) {return x & -x;}

void add(vll &arr, int x, int v) {
    while (x < N) {
        arr[x] += v;
        x += lowbit(x);
    }
}

ll sum(vll &arr, int x) {
    ll res = 0;
    while (x > 0) {
        res += arr[x];
        x -= lowbit(x);
    }
    return res;
}

ll rangeSum(vll &arr, int l, int r) {
    if (l > r) return 0;
    return sum(arr, r) - sum(arr, l - 1);
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
    go(i, 1, n) {
        cin >> a[i];
        do {
            b[i]++;
            a[i] &= a[i] - 1;
        } while (a[i]);
        pre[i] = pre[i - 1] + b[i];
    }

    ll res = 0;
    b[0] = 100;
    vi ma_st{0};
    go(i, 1, n) {
        while (!ma_st.empty() && b[ma_st.back()] <= b[i]) {
            ma_st.pop_back();
        }
        if (pre[i] % 2 == 0) {
            add(even, i, 1);
            int curMax = b[i];
            for (int j = (int)ma_st.size() - 1; j >= 0; --j) {
                int left = ma_st[j] + 1;
                int l = left - 1, r = (j == (int)ma_st.size() - 1) ? i : ma_st[j + 1];
                while (l < r) {
                    int mid = r - (r - l) / 2;
                    if (pre[i] - pre[mid - 1] >= 2 * curMax) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                if (l > left - 1) {
                    int right = l;
                    res += rangeSum(even, left - 1, right - 1);
                    if (left == 1) ++res;
                }

                curMax = b[ma_st[j]];
            }
        } else {
            add(odd, i, 1);
            int curMax = b[i];
            for (int j = (int)ma_st.size() - 1; j >= 0; --j) {
                int left = ma_st[j] + 1;
                int l = left - 1, r = (j == (int)ma_st.size() - 1) ? i : ma_st[j + 1];
                while (l < r) {
                    int mid = r - (r - l) / 2;
                    if (pre[i] - pre[mid - 1] >= 2 * curMax) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                if (l > left - 1) {
                    int right = l;
                    res += rangeSum(odd, left - 1, right - 1);
                }

                curMax = b[ma_st[j]];
            }
        }
        ma_st.pb(i);
    }
    cout << res;

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
