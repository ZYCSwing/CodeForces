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
    int n, m;
    cin >> n >> m;
    vector<int> res(n + 1, -1);
    unordered_set<int> can;
    for (int i = 1; i <= n; ++i) {
        can.insert(i);
    }
    int pre, l;
    for (int i = 0; i < m; ++i) {
        cin >> l;
        if (i) {
            int cand;
            if (l <= pre) {
                cand = l + n - pre;
            } else {
                cand = l - pre;
            }
            if (can.find(cand) == can.end()) {
                if (res[pre] != cand) {
                    cout << -1;
                    return 0;
                }
            } else {
                if (res[pre] == -1) {
                    res[pre] = cand;
                    can.erase(cand);
                } else if (res[pre] != cand) {
                    cout << -1;
                    return 0;
                }
            }
        }
        pre = l;
    }

    for (int i = 1; i <= n; ++i) {
        if (res[i] == -1) {
            res[i] = *can.begin();
            can.erase(can.begin());
        }
        cout << res[i];
        if (i < n) cout << " ";
    }

    return 0;
}