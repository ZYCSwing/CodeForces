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
int n, x;
unordered_map<int, int> cnt, tmp;

int main() {
    cin >> n >> x;

    if (n == 1) {
        cout << "YES" << endl << x;
        return 0;
    }

    cnt[0] = n;

    for (int i = 18; i >= 0; --i) {
        int bit = (x >> i) & 1;
        tmp.clear();
        int cnt1 = 0;
        for (auto item : cnt) {
            int foo = item.second / 2;
            if (foo) {
                tmp[item.first | (1 << i)] = foo;
                cnt1 += foo;
            }
            tmp[item.first] = item.second - foo;
        }
        if ((bit == 1 && cnt1 % 2 == 0)
            ||(bit == 0 && cnt1 % 2 == 1)) {
            auto item = *cnt.begin();
            int foo = item.second / 2;
            ++foo;
            tmp[item.first | (1 << i)] = foo;
            if (item.second - foo) {
                tmp[item.first] = item.second - foo;
            } else if (tmp.find(item.first) != tmp.end()){
                tmp.erase(item.first);
            }
        }
        cnt = tmp;
    }

    if (cnt.size() < n) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        for (auto item : cnt) {
            printf("%d ", item.first);
        }
        printf("\n");
    }

    return 0;
}