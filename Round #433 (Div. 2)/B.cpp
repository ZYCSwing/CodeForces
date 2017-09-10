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
#define MAXN 110
ll n, k;

int main() {
    cin >> n >> k;

    if (n == k || k == 0) {
        cout << 0 << " " << 0;
    } else if (3 * k >= n) {
        cout << 1 << " " << n - k;
    } else {
        cout << 1 << " " << 2 * k;
    }

    return 0;
}