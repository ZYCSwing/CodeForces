#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <list>

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <ctype.h>
using namespace std;

#define PI acos(-1.0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define si(x) scanf("%d", &x)

#define eps 1e-8
#define mod 1000000007

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/******************************** template ********************************/
#define MAXN 110
int n, k, x;
int a[MAXN];

int main() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 0;
    int i;
    for (i = n - 1; i >= 0 && i >= n - k; --i) {
        res += x;
    }
    while (i >= 0) {
        res += a[i];
        --i;
    }
    cout << res;

    return 0;
}