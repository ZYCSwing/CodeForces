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

int main() {
    int hh, mm;
    scanf("%d:%d", &hh, &mm);
    int rev = (hh % 10) * 10 + hh / 10;
    if (hh % 10 < 6 && rev >= mm) {
        cout << rev - mm;
    } else {
        int res = - mm;
        do {
            hh = (hh + 1) % 24;
            res += 60;
        } while (hh % 10 >= 6);
        rev = (hh % 10) * 10 + hh / 10;
        cout << res + rev;
    }

    return 0;
}