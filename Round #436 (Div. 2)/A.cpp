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
unordered_map<int, int> cnt;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    if (cnt.size() != 2) {
        cout << "NO";
    } else {
        int a = (*cnt.begin()).second;
        int b = (*next(cnt.begin())).second;
        if (a == b) {
            cout << "YES" << endl;
            cout << (*cnt.begin()).first << " " << (*next(cnt.begin())).fi;
        } else {
            cout << "NO";
        }
    }

    return 0;
}