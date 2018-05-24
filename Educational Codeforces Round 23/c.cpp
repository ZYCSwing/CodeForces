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

ll myPow(ll base, int exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) {
            res *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return res;
}

ll n, s;
vector<int> digits;
ll res;

void dfs(int index, bool all, ll ss) {
    int upper = all ? 9 : digits[index];

    for (int i = upper; i >= 0; --i) {
        ll tmp = myPow(10, index) * i - i;
        if (tmp >= ss) {
            res += ((all || i < upper) ? myPow(10, index) : n % myPow(10, index) + 1);
        } else if (tmp + myPow(10, index) - 1 - 9 * index < ss) {
            break;
        } else {
            dfs(index - 1, all || i < upper, ss - tmp);
        }
    }
}

int main() {
    cin >> n >> s;
    res = 0;
    ll nn = n;
    while (nn) {
        digits.push_back(nn % 10);
        nn /= 10;
    }
    dfs(digits.size() - 1, false, s);
    cout << res;

    return 0;
}