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
#define MAXN 70010
int n;
string phone[MAXN];

unordered_map<string, unordered_set<int>> dp[9];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> phone[i];
        for (int len = 1; len <= 8; ++len) {
            for (int s = 0; s + len <= 9; ++s) {
                dp[len][phone[i].substr(s, len)].insert(i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        bool found = false;
        string res;
        for (int len = 1; len <= 8; ++len) {
            for (int s = 0; s + len <= 9; ++s) {
                if (dp[len][phone[i].substr(s, len)].size() == 1) {
                    res = phone[i].substr(s, len);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        cout << (found ? res : phone[i]) << endl;
    }

    return 0;
}