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
int n;
string s;
unordered_map<int, int> dp;

int main() {
    cin >> n >> s;
    dp[0] = -1;
    int cur = 0;
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') {
            ++cur;
        } else {
            --cur;
        }
        if (dp.find(cur) != dp.end()) {
            res = max(res, i - dp[cur]);
        } else {
            dp[cur] = i;
        }
    }
    cout << res;

    return 0;
}