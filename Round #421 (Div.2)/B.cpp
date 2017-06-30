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

int n;
double a;

int main() {
    cin >> n >> a;
    double degree = 180.0 / n;
    int l = 1, r = n - 2;
    double diff;
    while (l < r) {
        int tmp = (r - l) / 3;
        int mid1 = l + tmp, mid2 = r - tmp;
        double res1 = mid1 * degree, res2 = mid2 * degree;
        if (fabs(res1 - a) < fabs(res2 - a)) {
            r = mid2 - 1;
        } else {
            l = mid1 + 1;
        }
    }
    cout << "2 1 " << 2 + l << endl;

    return 0;
}