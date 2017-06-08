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
vector<vector<char>> matrix;
vector<int> l, r;
int upper;

int main() {
    cin >> n >> m;
    matrix.resize(n);
    l.assign(n, m + 1);
    r.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        matrix[i].resize(m + 2);
    }
    upper = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m + 2; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == '1') {
                if (l[i] == m + 1) l[i] = j;
                r[i] = j;
            }
        }
        if (r[i] && upper == 0) upper = i;
    }

    if (upper == 0) {
        cout << r[0];
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 2 * r[0];
    dp[0][1] = m + 1;
    for (int i = 1; i < upper; ++i) {
        dp[i][0] = min(dp[i - 1][0] + 2 * r[i], dp[i - 1][1] + m + 1);
        dp[i][1] = min(dp[i - 1][0] + m + 1, dp[i - 1][1] + 2 * (m + 1 - l[i]));
    }
    cout << upper + min(dp[upper - 1][0] + r[upper], dp[upper - 1][1] + (m + 1 - l[upper]));

    return 0;
}