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

int n;
vector<int> a, b;

vector<int> solve(vector<int>& nums) {
    int sum = 0;
    vector<int> index(n + 1, -1);
    int dup1, dup2, miss;
    for (int i = 0; i < n; ++i) {
        if (index[nums[i]] == -1) {
            index[nums[i]] = i;
        } else {
            dup1 = index[nums[i]];
            dup2 = i;
        }
        sum += nums[i];
    }
    miss = n * (n + 1) / 2 - (sum - nums[dup1]);
    return {dup1, dup2, miss};
}

int main() {
    cin >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> foo = solve(a);

    a[foo[0]] = foo[2];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) ++cnt;
    }
    if (cnt != 1) {
        a[foo[0]] = a[foo[1]];
        a[foo[1]] = foo[2];
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << a[i];
    }

    return 0;
}