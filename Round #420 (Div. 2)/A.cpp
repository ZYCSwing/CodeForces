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

int n;

int main() {
    cin >> n;
    vector<vector<int>> lab(n, vector<int>(n));
    vector<unordered_set<int>> rows(n), cols(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> lab[i][j];
            rows[i].insert(lab[i][j]);
            cols[j].insert(lab[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (lab[i][j] == 1) continue;
            bool flag = false;
            for (int k : rows[i]) {
                if (cols[j].find(lab[i][j] - k) != cols[j].end()) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";

    return 0;
}