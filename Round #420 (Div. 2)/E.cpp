#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <numeric>
#include <cmath>
#include <memory.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<int>> vvi;

#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-8

#define MAXN 101

int n;
ll k;
ll a[MAXN], b[MAXN];
int c[MAXN];

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>>& b) {
    int m = a.size(), n = a[0].size(), r = b[0].size();
    vector<vector<ll>> res(m, vector<ll>(r, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < r; ++j) {
            for (int l = 0; l < n; ++l) {
                res[i][j] += a[i][l] * b[l][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<ll>> myPow(vector<vector<ll>> base, ll exp) {
    int n = base.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    while (exp) {
        if (exp & 1) {
            res = mul(res, base);
        }
        base = mul(base, base);
        exp >>= 1;
    }
    return res;
}

vector<vector<ll>> gen(int sz) {
    if (sz == 1) return {{1}};
    vector<vector<ll>> res(sz, vector<ll>(sz, 0));

    res[0][0] = res[0][1] = 1;
    res[sz - 1][sz - 1] = res[sz - 1][sz - 2] = 1;
    for (int i = 1; i < sz - 1; ++i) {
        res[i][i - 1] = res[i][i] = res[i][i + 1] = 1;
    }

    return res;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<ll> input(c[0] + 1, 0), output;
    input[0] = 1;

    for (int i = 0; i < n; ++i) {
        vector<vector<ll>> tmp = gen(c[i] + 1);
        tmp = myPow(tmp, min(b[i], k) - a[i]);
        output = mul({input}, tmp)[0];

        if (b[i] >= k) break;
        if (i < n - 1) {
            input.resize(c[i + 1] + 1);
            for (int j = 0; j <= c[i + 1]; ++j) {
                input[j] = (j <= c[i] ? output[j] : 0);
            }
        }
    }
    cout << output[0];

    return 0;
}