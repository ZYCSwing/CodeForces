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

#define pb push_back
#define all(x) (x).begin(), (x).end()

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
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    int cnt = 0;
    while (c > 0) {
        ++cnt;
        c -= v0;
        if (c <= 0) break;
        v0 = min(v0 + a, v1);
        c += l;
    }
    cout << cnt;

    return 0;
}