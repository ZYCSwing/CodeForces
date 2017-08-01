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

#define MAXN 350010

int n, a, b;

bool check(ll a, ll b) {
    ll tmp = a * b;
    ll base = (ll)ceil(pow(tmp, 1.0 / 3));
    if (base * base * base != tmp) {
        return false;
    }
    if (a % base != 0 || b % base != 0) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        cout << (check(a, b) ? "Yes" : "No") << endl;
    }

    return 0;
}