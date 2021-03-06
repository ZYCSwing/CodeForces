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

string calu(string s1, string s2) {
    reverse(all(s1));
    reverse(all(s2));
    int l1 = s1.length();
    int l2 = s2.length();
    vector<int> res;
    int c = 0;
    for (int i = 0; i < max(l1, l2); ++i) {
        int n1 = i < l1 ? s1[i] - '0' : 0;
        int n2 = i < l2 ? s2[i] - '0' : 0;
        int tmp = n1 + n2 + c;
        res.pb(tmp % 10);
        c = tmp / 10;
    }
    if (c) res.pb(c);

    string ret;
    while (!res.empty()) {
        ret.pb('0' + res.back());
        res.pop_back();
    }
    return ret;
}

bool small(string s1, string s2) {
    return s1.length() < s2.length() || (s1.length() == s2.length() && s1 < s2);
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
    int l;
    string s;
    cin >> l >> s;
    if (l % 2 == 0) {
        string s1 = s.substr(0, l / 2);
        string s2 = s.substr(l / 2);
        if (s2[0] != '0') {
            cout << calu(s1, s2);
            return 0;
        } else {
            bool has = false;
            string res;
            for (int i = l / 2 + 1; i < l; ++i) if (s[i] != '0') {
                s1 = s.substr(0, i);
                s2 = s.substr(i);
                has = true;
                res = calu(s1, s2);
                break;
            }
            for (int i = l / 2 - 1; i >= 0; --i) if (s[i] != '0') {
                s1 = s.substr(0, i);
                s2 = s.substr(i);
                string tmp = calu(s1, s2);
                if (!has || small(tmp, res)) {
                    res = tmp;
                }
                break;
            }
            cout << res;
            return 0;
        }
    } else {
        bool has = false;
        string s1, s2, res;
        for (int i = l / 2 + 1; i < l; ++i) if (s[i] != '0') {
            s1 = s.substr(0, i);
            s2 = s.substr(i);
            has = true;
            res = calu(s1, s2);
            break;
        }
        for (int i = l / 2; i >= 0; --i) if (s[i] != '0') {
                s1 = s.substr(0, i);
                s2 = s.substr(i);
                string tmp = calu(s1, s2);
                if (!has || small(tmp, res)) {
                    res = tmp;
                }
                break;
            }
        cout << res;
    }

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
