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

#define MAXN 100010

int n, res, toerr;
set<int> ss;

int main() {
    cin >> n;
    res = 0, toerr = 0;
    for (int i = 0; i < 2 * n; ++i) {
        string op;
        cin >> op;
        if (op == "add") {
            int num;
            cin >> num;
            if (!ss.empty() && *(ss.begin()) < num) {
                toerr = 1;
            } else if (toerr) {
                ++toerr;
            }
            ss.insert(num);
        } else {
            if (toerr) {
                --toerr;
                if (toerr == 0) ++res;
            }
            ss.erase(ss.begin());
        }
    }
    cout << res;

    return 0;
}