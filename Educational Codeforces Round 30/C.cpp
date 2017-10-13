#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <list>

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <ctype.h>
using namespace std;

#define PI acos(-1.0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define si(x) scanf("%d", &x)

#define eps 1e-8
#define mod 1000000007

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/******************************** template ********************************/
#define MAXN 110
int n, m, k;
int grid[MAXN][MAXN];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int res = 0, remove = 0;
    for (int col = 0; col < m; ++col) {
        int up = 0, down;
        int cur = 0, curDel = 0;
        for (down = 0; down - up + 1 <= k; ++down) {
            if (grid[down][col] == 1) ++cur;
        }
        int most = 0, del = 0;
        for (; down <= n; ++up, ++down) {
            if (cur > most) {
                most = cur;
                del = curDel;
            }
            if (grid[up][col] == 1) {
                ++curDel;
                --cur;
            }
            if (down < n && grid[down][col] == 1) {
                ++cur;
            }
        }
        res += most;
        remove += del;
    }
    cout << res << " " << remove;

    return 0;
}