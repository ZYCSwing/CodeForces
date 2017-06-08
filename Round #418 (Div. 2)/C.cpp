#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <numeric>
#include <cmath>
#include <memory.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<int>> vvi;

#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-8

int n, q;
string str;
vvi indexs(26);
vector<vector<pii>> foo(26);

void solve() {
    int m;
    char ch;
    cin >> m >> ch;
    if (indexs[ch - 'a'].size() + m >= n) {
        cout << n << endl;
        return;
    }

    if (foo[ch - 'a'].size() == 1) {
        cout << min(n, (int)indexs[ch - 'a'].size() + m) << endl;
        return;
    }
    int res = 0;
    int l = 0, r = 0, cnt = 0, remain = m;
    while (r < foo[ch - 'a'].size()) {
        if (l == r) {
            cnt = foo[ch - 'a'][l].second - foo[ch - 'a'][l].first + 1;
            ++r;
            res = max(res, cnt);
        } else {
            int len = foo[ch - 'a'][r].first - foo[ch - 'a'][r - 1].second - 1;
            if (len <= remain) {
                cnt += foo[ch - 'a'][r].second - foo[ch - 'a'][r - 1].second;
                remain -= len;
                ++r;
                res = max(res, cnt);
            } else {
                res = max(res, cnt + remain);
                if (l < r - 1) {
                    cnt -= (foo[ch - 'a'][l + 1].first - foo[ch - 'a'][l].first);
                    remain += foo[ch - 'a'][l + 1].first - foo[ch - 'a'][l].second - 1;
                } else {
                    cnt -= foo[ch - 'a'][l].second - foo[ch - 'a'][l].first + 1;
                }
                ++l;
            }
        }
    }
    res = max(res, cnt + remain);

    cout << res << endl;
}

int main() {
    cin >> n >> str >> q;
    for (int i = 0; i < n; ++i) {
        indexs[str[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < 26; ++i) {
        pii tmp;
        for (int j = 0; j < indexs[i].size(); ++j) {
            if (j == 0) {
                tmp = {indexs[i][0], indexs[i][0]};
            } else if (indexs[i][j] == tmp.second + 1) {
                ++tmp.second;
            } else {
                foo[i].push_back(tmp);
                tmp = {indexs[i][j], indexs[i][j]};
            }
        }
        foo[i].push_back(tmp);
    }
    for (int i = 0; i < q; ++i) {
        solve();
    }

    return 0;
}