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
#define MAXN 100010
int n;
int pos0 = -1, pos1 = -1;

void ask(string s) {
    cout << "? " << s << endl;
}

// dist : hamming distance when "all 0 in [l, r], all 1 in other position"
void solve(int l, int r, int cnt0, int cnt1, int dist) {
    if (cnt0 == 0) pos1 = l;
    if (cnt1 == 0) pos0 = l;
    if (pos0 != -1 && pos1 != -1) {
        printf("! %d %d", pos0 + 1, pos1 + 1);
        exit(0);
    }
    if (cnt0 == 0 || cnt1 == 0) return;

    int mid = l + (r - l) / 2;
    string tmp;
    for (int i = 0; i <= mid; ++i) {
        tmp.pb('1');
    }
    for (int i = mid + 1; i <= r; ++i) {
        tmp.pb('0');
    }
    for (int i = r + 1; i < n; ++i) {
        tmp.pb('1');
    }

    int l0, l1, r0, r1, diff, len = mid - l + 1;

    ask(tmp);
    cin >> diff;
    l0 = (len - dist + diff) / 2;
    l1 = mid - l + 1 - l0;
    r0 = cnt0 - l0;
    r1 = cnt1 - l1;

    solve(l, mid, l0, l1, dist - r1 + r0);
    solve(mid + 1, r, r0, r1, dist - l1 + l0);
}

int main() {
    cin >> n;

    string foo;
    for (int i = 0; i < n; ++i) {
        foo.pb('0');
    }
    ask(foo);
    int cnt1;
    cin >> cnt1;
    solve(0, n - 1, n - cnt1, cnt1, cnt1);

    return 0;
}