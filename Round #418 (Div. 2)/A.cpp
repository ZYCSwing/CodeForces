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

int n, k;

int main() {
    cin >> n >> k;
    if (k > 1) {
        cout << "Yes";
        return 0;
    }
    vector<int> a(n);
    int index;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i && a[i] != 0 && a[i] < a[i - 1]) {
            cout << "Yes";
            return 0;
        }
        if (a[i] == 0) index = i;
    }
    cin >> a[index];
    if ((index == 0 || a[index] > a[index - 1]) && (index == n - 1 || a[index] < a[index + 1])) {
        cout << "No";
    } else {
        cout << "Yes";
    }

    return 0;
}