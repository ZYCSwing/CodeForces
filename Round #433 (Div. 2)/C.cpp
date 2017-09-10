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
#define MAXN 300010
int n, k;
int res[MAXN];

struct foo {
    int origin;
    int cost;
}f[MAXN];

bool cmp(foo a, foo b) {
    return a.cost > b.cost || (a.cost == b.cost && a.origin < b.origin);
}

set<int> avv;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        f[i].origin = i;
        scanf("%d", &f[i].cost);
    }
    sort(f + 1, f + n + 1, cmp);

    for (int i = k + 1; i <= k + n; ++i) {
        avv.insert(i);
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        int val = max(k + 1, f[i].origin);
        int index = *avv.lower_bound(val);
        res[f[i].origin] = index;
        sum += 1LL * f[i].cost * (index - f[i].origin);
        avv.erase(index);
    }

    cout << sum << endl;
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", res[i], " \n"[i == n]);
    }

    return 0;
}