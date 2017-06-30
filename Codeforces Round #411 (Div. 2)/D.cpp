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
    string str;
    cin >> str;
    ll res = 0, cnt = 0;
    ll len = str.length();
    for (int i = len - 1; i >= 0; --i) {
        if (str[i] == 'b') {
            cnt = (cnt + 1) % mod;
        } else {
            res = (res + cnt) % mod;
            cnt = (cnt << 1) % mod;
        }
    }
    cout << res;

    return 0;
}