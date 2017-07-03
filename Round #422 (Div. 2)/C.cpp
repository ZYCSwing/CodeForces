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

// 扩展欧几里得算法 res[1] * a + res[2] * b = res[0] = gcd(a, b)
vector<int> extendGcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    } else {
        vector<int> tmp = extendGcd(b, a % b);
        return {tmp[0], tmp[2], tmp[1] - (a / b) * tmp[2]};
    }
}

// 带模快速幂
ll myPow(ll base, int exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// 求逆元
ll inv(ll a) {
    return myPow(a, mod - 2);
}

#define MAXFAC 100010

ll fac[MAXFAC];

void initFac() {
    fac[0] = 1;
    for (int i = 1; i < MAXFAC; ++i) {
        fac[i] = i * fac[i - 1] % mod;
    }
}

ll Combine(ll a, ll b) {
    return (fac[a] * inv(fac[b]) % mod) * inv(fac[a - b]) % mod;
}

/******************************** template ********************************/
int n, x;
struct vocation{
    int l;
    int r;
    int cost;
    int len;
};

vector<vocation> vocs;

unordered_map<int, int> foo;

bool cmp(vocation a, vocation b) {
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}

int main() {
    cin >> n >> x;
    vocs.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> vocs[i].l >> vocs[i].r >> vocs[i].cost;
        vocs[i].len = vocs[i].r - vocs[i].l + 1;
    }

    sort(all(vocs), cmp);

    int res = -1;

    auto cmp2 = [](int a, int b) {return vocs[a].r > vocs[b].r;};
    priority_queue<int, vector<int>, decltype(cmp2)> pq(cmp2);
    for (int cur = 0; cur < n; ++cur) {
        while (!pq.empty() && vocs[pq.top()].r < vocs[cur].l) {
            int index = pq.top();
            pq.pop();
            if (foo.find(vocs[index].len) == foo.end()) {
                foo[vocs[index].len] = vocs[index].cost;
            } else {
                foo[vocs[index].len] = min(foo[vocs[index].len], vocs[index].cost);
            }
        }
        if (foo.find(x - vocs[cur].len) != foo.end()) {
            if (res == -1) {
                res = vocs[cur].cost + foo[x - vocs[cur].len];
            } else {
                res = min(res, vocs[cur].cost + foo[x - vocs[cur].len]);
            }
        }
        pq.push(cur);
    }
    cout << res;

    return 0;
}