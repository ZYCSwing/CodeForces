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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<int>> vvi;

#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-8

int solveMin(vector<int>& a, int n) {
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (n <= a[i]) {
            res += (2 * a[i] - n + 1) * n / 2;
            break;
        } else {
            res += (a[i] + 1) * a[i] / 2;
            n -= a[i];
        }
    }
    return res;
}

int solveMax(vector<int> a, int n) {
    int res = 0, sz = a.size();
    for (int i = sz - 1; i;) {
        if (a[i] > a[i - 1]) {
            if (sz - i >= n) {
                res += n * a[i];
                return res;
            }
            res += (sz - i) * a[i];
            n -= (sz - i);
            --a[i];
        } else {
            --i;
        }
    }
    while (n) {
        res += min(n, sz) * a[0];
        n -= min(n, sz);
        --a[0];
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    cout << solveMax(a, n) << " " << solveMin(a, n);

    return 0;
}