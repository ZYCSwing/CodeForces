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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

pii p[3];

bool check2(pii& p0, pii& p1, pii& p2) {
    if (p0.fi == p1.fi) {
        int upper = max(p0.se, p1.se);
        int lower = min(p0.se, p1.se);
        if (p2.se >= upper || p2.se <= lower) return true;
    }

    if (p0.se == p1.se) {
        int upper = max(p0.fi, p1.fi);
        int lower = min(p0.fi, p1.fi);
        if (p2.fi >= upper || p2.fi <= lower) return true;
    }

    return false;
}

int main() {
    for (int i = 0; i < 3; ++i) {
        cin >> p[i].fi >> p[i].se;
    }

    if (p[0].fi == p[1].fi && p[1].fi == p[2].fi) {
        cout << 1;
        return 0;
    }

    if (p[0].se == p[1].se && p[1].se == p[2].se) {
        cout << 1;
        return 0;
    }

    if (check2(p[0], p[1], p[2]) || check2(p[0], p[2], p[1]) || check2(p[1], p[2], p[0])) {
        cout << 2;
        return 0;
    }

    cout << 3;

    return 0;
}