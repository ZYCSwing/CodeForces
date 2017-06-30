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

#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<ll, int> pli;
typedef vector<vector<int>> vvi;

#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-8

int d, n, m;
vector<int> X1, Y1, X2, Y2;
int cntL, cntR, cntT, cntB;

vector<int> L, T, R, B;

int lowbit(int x) {return x & -x;}

void add(vector<int>& vec, int index, int val) {
    while (index < vec.size()) {
        vec[index] += val;
        index += lowbit(index);
    }
}

int sum(vector<int>& vec, int index) {
    int res = 0;
    while (index) {
        res += vec[index];
        index -= lowbit(index);
    }
    return res;
}

int main() {
    cin >> d >> n >> m;
    X1.resize(d);
    Y1.resize(d);
    X2.resize(d);
    Y2.resize(d);

    L.assign(n + 1, 0);
    R.assign(n + 1, 0);
    T.assign(m + 1, 0);
    B.assign(m + 1, 0);

    for (int i = 0; i < d; ++i) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        add(L, min(X1[i], X2[i]), 1);
        add(T, min(Y1[i], Y2[i]), 1);
        add(R, n + 1 - max(X1[i], X2[i]), 1);
        add(B, m + 1 - max(Y1[i], Y2[i]), 1);
    }
    cin >> cntL >> cntR >> cntT >> cntB;

    for (int i = 0; i < d; ++i) {
        int lll = min(X1[i], X2[i]), rrr = max(X1[i], X2[i]), ttt = min(Y1[i], Y2[i]), bbb = max(Y1[i], Y2[i]);
        add(L, lll, -1);
        add(T, ttt, -1);
        add(R, n + 1 - rrr, -1);
        add(B, m + 1 - bbb, -1);

        if (sum(L, rrr - 1) == cntL && sum(R, n - lll) == cntR
            && sum(T, bbb - 1) == cntT && sum(B, m - ttt) == cntB) {
            cout << i + 1;
            return 0;
        }

        add(L, lll, 1);
        add(T, ttt, 1);
        add(R, n + 1 - rrr, 1);
        add(B, m + 1 - bbb, 1);
    }

    cout << -1;

    return 0;
}