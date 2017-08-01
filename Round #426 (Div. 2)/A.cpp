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

unordered_map<char, int> mm;

int main() {
    mm['<'] = 0;
    mm['^'] = 1;
    mm['>'] = 2;
    mm['v'] = 3;
    char a, b;
    int n;
    cin >> a >> b;
    cin >> n;
    if (abs(mm[a] - mm[b]) % 2 == 0) {
        cout << "undefined";
    } else {
        n %= 4;
        if ((mm[a] + n) % 4 == mm[b]) {
            cout << "cw";
        } else {
            cout << "ccw";
        }
    }

    return 0;
}