#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <ctype.h>
using namespace std;

#define PI acos(-1.0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

#define eps 1e-8
#define mod 1000000007

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

/******************************** template ********************************/
#define MAXN 100010
int n;
vector<int> edges[MAXN];

ll cnt[2] = {0, 0};

void dfs(int cur, int label, int from) {
    ++cnt[label];
    for (int next :edges[cur]) {
        if (next == from) continue;
        dfs(next, 1 ^ label, cur);
    }
}

int main() {
    cin >> n;
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v);
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs(1, 0, -1);

    if (cnt[1] == 0) {
        cout << 0;
    } else {
        ll res = cnt[0] * cnt[1] - (n - 1);
        cout << res;
    }

    return 0;
}