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
#define MAXN 1000010
int n, m;
int loop = 0;
vector<int> edges[MAXN];

int p[MAXN];
unordered_set<int> nodes;

int Find(int x) {
    if (p[x] == -1) return x;
    if (x != p[x]) {
        p[x] = Find(p[x]);
    }
    return p[x];
}

bool Union(int a, int b) {
    int roota = Find(a), rootb = Find(b);

    if (roota != rootb) {
        p[roota] = rootb;
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    memset(p, -1, sizeof(p));
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        nodes.insert(u);
        nodes.insert(v);
        if (u == v) {
            ++loop;
        } else {
            edges[u].pb(v);
            edges[v].pb(u);
            Union(u, v);
        }
    }

    int pp = -1;
    for (int i : nodes) {
        if (pp == -1) {
            pp = Find(i);
        } else {
            if (pp != Find(i)) {
                cout << 0;
                return 0;
            }
        }
    }

    ll res = 0;
    if (loop) {
        res += 1LL * loop * (loop - 1) / 2;
        res += 1LL * loop * (m - loop);
    }

    for (int i : nodes) {
        int sz = edges[i].size();
        if (sz > 1) {
            res += 1LL * sz * (sz - 1) / 2;
        }
    }

    cout << res;

    return 0;
}