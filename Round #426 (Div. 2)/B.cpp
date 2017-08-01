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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

#define MAXN 100010

int n, k;
string s;
int last[26];

int main() {
    cin >> n >> k;
    cin >> s;

    memset(last, -1, sizeof(last));

    for (int i = n - 1; i >= 0; --i) {
        if (last[s[i] - 'A'] == -1) {
            last[s[i] - 'A'] = i;
        }
    }

    unordered_set<int> ss;
    for (int i = 0; i < n; ++i) {
        if (ss.find(s[i] - 'A') == ss.end()) {
            ss.insert(s[i] - 'A');
            if (ss.size() > k) {
                cout << "YES";
                return 0;
            }
        }
        if (i == last[s[i] - 'A']) {
            ss.erase(s[i] - 'A');
        }
    }

    cout << "NO";

    return 0;
}