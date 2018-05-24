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


vector<int> a;

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[2] == a[0]) {
        int i;
        for (i = 3; i < n; ++i) {
            if (a[i] != a[0]) break;
        }
        cout << 1LL * i * (i - 1) * (i - 2) / 6;
        return 0;
    } else if (a[2] == a[1]) {
        int i;
        for (i = 3; i < n; ++i) {
            if (a[i] != a[1]) break;
        }
        cout << 1LL * (i - 1) * (i - 2) / 2;
        return 0;
    } else {
        int i;
        for (i = 3; i < n; ++i) {
            if (a[i] != a[2]) break;
        }
        cout << i - 2;
    }

    return 0;
}