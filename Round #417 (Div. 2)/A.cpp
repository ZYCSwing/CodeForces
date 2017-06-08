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

int main() {
    vector<int> l(4), s(4), r(4), p(4);
    for (int i = 0; i < 4; ++i) {
        cin >> l[i] >> s[i] >> r[i] >> p[i];
    }

    for (int i = 0; i < 4; ++i) {
        if (p[i] & (l[i] | s[i] | r[i] | l[(i + 1) % 4] | s[(i + 2) % 4] | r[(i + 3) % 4])) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}