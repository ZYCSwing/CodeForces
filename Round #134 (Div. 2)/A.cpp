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
    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n + 1);
    for (int i = 0; i < 2 * n + 1; ++i) {
        cin >> a[i];
    }
    for (int i = 1, cnt = 0; i < 2 * n && cnt < k; i += 2) {
        if (a[i] - a[i - 1] > 1 && a[i] - a[i + 1] > 1) {
            --a[i];
            ++cnt;
        }
    }
    for (int i = 0; i < 2 * n + 1; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }

    return 0;
}