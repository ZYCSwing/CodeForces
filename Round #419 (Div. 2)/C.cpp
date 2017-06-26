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

int n, m;
int g[101][101], f[101][101];
int cnt;

int main() {
    memset(f, 0, sizeof(f));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    cnt = 0;

    int minr = INT_MAX;
    for (int i = 0; i < n; ++i) minr = min(minr, g[i][0]);

    for (int i = 0; i < n; ++i) {
        int val = g[i][0] - minr;
        cnt += val;
        for (int j = 0; j < m; ++j) {
            f[i][j] += val;
        }
    }

    int minc = INT_MAX;
    for (int i = 0; i < m; ++i) minc = min(minc, g[0][i]);

    for (int i = 0; i < m; ++i) {
        int val = g[0][i] - minc;
        cnt += val;
        for (int j = 0; j < n; ++j) {
            f[j][i] += val;
        }
    }

    int diff;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                diff = g[i][j] - f[i][j];
            } else {
                if (g[i][j] - f[i][j] != diff) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << cnt + min(n, m) * diff << endl;
    for (int i = 0; i < n; ++i) {
        int val = g[i][0] - minr;
        while (val--) {
            cout << "row " << i + 1 << endl;
        }
    }
    for (int i = 0; i < m; ++i) {
        int val = g[0][i] - minc;
        while (val--) {
            cout << "col " << i + 1 << endl;
        }
    }
    if (n < m) {
        for (int i = 0; i < diff; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << "row " << j + 1 << endl;
            }
        }
    } else {
        for (int i = 0; i < diff; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << "col " << j + 1 << endl;
            }
        }
    }

    return 0;
}