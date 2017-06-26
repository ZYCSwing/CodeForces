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

#define MAXN 200010

int n, k, q;
int foo[MAXN], bar[MAXN];

int lowbit(int x) {return x & -x;}

void add(int x) {
    while (x < MAXN) {
        ++bar[x];
        x += lowbit(x);
    }
}

int sum(int x) {
    int res = 0;
    while (x) {
        res += bar[x];
        x -= lowbit(x);
    }
    return res;
}

int query(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    cin >> n >> k >> q;
    memset(foo, 0, sizeof(foo));
    memset(bar, 0, sizeof(bar));
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        ++foo[l];
        --foo[r + 1];
    }
    for (int i = 1; i < MAXN; ++i) {
        foo[i] += foo[i - 1];
        if (foo[i] >= k) add(i);
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << endl;
    }

    return 0;
}