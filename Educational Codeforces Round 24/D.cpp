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

unordered_map<int, int> cnt;
int cntA;

int main() {
    int n, a;
    cin >> n >> a;
    cntA = 0;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (c == a) {
            ++cntA;
            for (auto it = cnt.begin(); it != cnt.end();) {
                if ((*it).second < cntA) {
                    it = cnt.erase(it);
                } else {
                    ++it;
                }
            }
            if (cnt.empty()) {
                cout << -1;
                return 0;
            }
        } else {
            if (cntA == 0) {
                ++cnt[c];
            } else {
                if (cnt.find(c) != cnt.end()) ++cnt[c];
            }
        }
    }
    cout << (*cnt.begin()).first;

    return 0;
}