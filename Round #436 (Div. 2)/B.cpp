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
#define MAXN 200010
int n;
string s;
unordered_set<char> cc;

int main() {
    cin >> n;
    cin >> s;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            res = max(res, (int)cc.size());
            cc.clear();
        } else {
            cc.insert(s[i]);
        }
    }

    res = max(res, (int)cc.size());
    cout << res;

    return 0;
}