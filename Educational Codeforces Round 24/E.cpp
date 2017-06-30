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

#define N 100010

int n, k;
ll res;
vector<int> a, R;
vector<bool> prime;

void solve(int pp) {
    int c = 0;
    while (k % pp == 0) {
        ++c;
        k /= pp;
    }
    vector<int> tmp(N, 0);
    for (int i = 0; i < n; ++i) {
        while (a[i] % pp == 0) {
            ++tmp[i];
            a[i] /= pp;
        }
    }

    for (int i = 0, j = -1, cur = 0; i < n; ++i) {
        while (cur < c && j < n) cur += tmp[++j];
        R[i] = max(R[i], j);
        cur -= tmp[i];
    }
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (k == 1) {
        cout << 1LL * n * (n + 1) / 2;
        return 0;
    }

    R.assign(n, 0);
    prime.assign(N, true);
    for (int i = 2; i < N; ++i) {
        if (prime[i]) {
            if (k % i == 0) solve(i);
            for (int j = 2 * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
    if (k > 1) solve(k);
    res = 0;
    for (int i = 0; i < n; ++i) {
        res += n - R[i];
    }
    cout << res;

    return 0;
}