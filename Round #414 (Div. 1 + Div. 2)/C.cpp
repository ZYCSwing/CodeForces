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

#define MAXN 100010

string a, b;
string res1, res2;
int n, la, ra, lb, rb;

int main() {
    cin >> a >> b;
    n = a.length();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    la = 0, ra = (n - 1) / 2;
    lb = (n + 1) / 2, rb = n - 1;
    bool first = true;
    while (res1.length() + res2.length() < n) {
        if (first) {
            if (a[la] < b[rb]) {
                res1.push_back(a[la++]);
            } else {
                res2.push_back(a[ra--]);
            }
            first = false;
        } else {
            if (a[la] < b[rb]) {
                res1.push_back(b[rb--]);
            } else {
                res2.push_back(b[lb++]);
            }
            first = true;
        }
    }
    reverse(res2.begin(), res2.end());
    cout << res1 + res2;

    return 0;
}