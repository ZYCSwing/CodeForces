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

int main() {
    int n;
    cin >> n;
    ll res = 1, zero = 0;
    bool first = true;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            if (first) {
                first = false;
            } else {
                res *= (zero + 1);
            }
            zero = 0;
        } else {
            ++zero;
        }
    }
    cout << (first ? 0 : res);

    return 0;
}