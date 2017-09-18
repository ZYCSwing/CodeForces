#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <ctype.h>
using namespace std;

#define PI acos(-1.0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

#define eps 1e-8
#define mod 1000000007

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

/******************************** template ********************************/
#define MAXN 1000010

int main() {
    int n, k;
    cin >> n >> k;
    int cnt2 = 0, cnt5 = 0;
    int tmp = n;
    while (tmp % 2 == 0) {
        ++cnt2;
        tmp /= 2;
    }
    while (tmp % 5 == 0) {
        ++cnt5;
        tmp /= 5;
    }
    if (k <= min(cnt2, cnt5)) {
        cout << n;
    } else {
        ll res = n;
        while (cnt2 < k) {
            res *= 2;
            ++cnt2;
        }
        while (cnt5 < k) {
            res *= 5;
            ++cnt5;
        }
        cout << res;
    }

    return 0;
}