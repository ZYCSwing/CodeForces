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
string s;
unordered_set<char> ss{'a', 'e', 'i', 'o', 'u'};
unordered_set<char> foo;

int main() {
    cin >> s;
    string tmp;
    int l = 0;
    for (int r = 0; r < s.length(); ++r) {
        if (ss.find(s[r]) != ss.end()) {
            l = r + 1;
            foo.clear();
        } else {
            foo.insert(s[r]);
            if (r - l + 1 >= 3 && foo.size() > 1) {
                s.insert(s.begin() + r, ' ');
                foo.clear();
                l = r + 1;
            }
        }
    }
    cout << s;

    return 0;
}