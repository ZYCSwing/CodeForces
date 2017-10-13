#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <list>

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <ctype.h>
using namespace std;

#define PI acos(-1.0)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define si(x) scanf("%d", &x)

#define eps 1e-8
#define mod 1000000007

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/******************************** template ********************************/
#define MAXN 100010
int n, k;

vector<int> solve(int nn, int kk) {
    --kk;
    vector<int> res;
    if (kk == 0) {
        for (int i = 1; i <= nn; ++i) {
            res.pb(i);
        }
    } else {
        if (kk % 4 == 2) {
            res = solve(nn / 2, kk / 2);
            vector<int> right = solve(nn - nn / 2, kk / 2);
            for (int i = nn / 2; i < nn; ++i) {
                res.pb(right[i - nn / 2] + nn / 2);
            }
            int leftMax = nn / 2, rightMin = nn / 2 + 1;
            for (int i = 0; i < nn; ++i) {
                if (res[i] == leftMax) {
                    res[i] = rightMin;
                } else if (res[i] == rightMin) {
                    res[i] = leftMax;
                }
            }
        } else {
            res = solve(nn / 2, kk / 2 - 1);
            vector<int> right = solve(nn - nn / 2, kk / 2 + 1);
            for (int i = nn / 2; i < nn; ++i) {
                res.pb(right[i - nn / 2] + nn / 2);
            }
            int leftMax = nn / 2, rightMin = nn / 2 + 1;
            for (int i = 0; i < nn; ++i) {
                if (res[i] == leftMax) {
                    res[i] = rightMin;
                } else if (res[i] == rightMin) {
                    res[i] = leftMax;
                }
            }
        }
    }
    return res;
}

int main() {
    cin >> n >> k;
    if (k % 2 == 0 || k > n * 2) {
        cout << -1;
    } else {
        vector<int> res = solve(n, k);
        for (int i = 0; i < n; ++i) {
            printf("%d%c", res[i], " \n"[i == n - 1]);
        }
    }

    return 0;
}