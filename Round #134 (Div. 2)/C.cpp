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

int p[100], x[100], y[100];

int root(int node) {
    if (p[node] == -1) return node;
    if (node != p[node]) {
        p[node] = root(p[node]);
    }
    return p[node];
}

bool merge(int node1, int node2) {
    int root1 = root(node1), root2 = root(node2);
    if (root1 != root2) {
        p[root1] = root2;
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    memset(p, -1, sizeof(p));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        ++cnt;
        for (int j = 0; j < i; ++j) {
            if (x[i] == x[j] || y[i] == y[j]) {
                if (merge(i, j)) --cnt;
            }
        }
    }
    cout << cnt - 1;

    return 0;
}