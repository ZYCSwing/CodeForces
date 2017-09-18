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

int main() {
    ll l = 1, r = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll flat, flo;
        cin >> flat >> flo;

        if (flo > 1) {
            if (flat % (flo - 1) == 0) {
                r = min(r, flat / (flo - 1) - 1);
            } else {
                r = min(r, flat / (flo - 1));
            }
        }

        l = max(l, (flat + flo - 1) / flo);
    }

    ll lower = (n + r - 1) / r, upper = (n + l - 1) / l;

    cout << (lower == upper ? lower : -1);

    return 0;
}