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

unordered_set<string> examples, regular;
unordered_set<int> wrongexample, wrongregular;
unordered_set<int> freeexample, freeregular;

int main() {
    cin >> n;
    string name;
    int type;
    for (int i = 0; i < n; ++i) {
        cin >> name >> type;
        if (type) {
            examples.insert(name);
        } else {
            regular.insert(name);
        }
    }
    int cnt1 = examples.size(), cnt0 = regular.size();

    for (int i = 1; i <= cnt1; ++i) {
        freeexample.insert(i);
        string key = to_string(i);
        if (examples.find(key) != examples.end()) {
            freeexample.erase(i);
            examples.erase(key);
        } else if (regular.find(key) != regular.end()) {
            wrongexample.insert(i);
            freeexample.erase(i);
        }
    }

    for (int i = cnt1 + 1; i <= n; ++i) {
        freeregular.insert(i);
        string key = to_string(i);
        if (regular.find(key) != regular.end()) {
            freeregular.erase(i);
            regular.erase(key);
        } else if (examples.find(key) != examples.end()) {
            wrongregular.insert(i);
            freeregular.erase(i);
        }
    }

    vector<string> res;
    while ((!freeexample.empty() && !wrongregular.empty()) || (!freeregular.empty() && !wrongexample.empty())) {
        while (!freeexample.empty() && !wrongregular.empty()) {
            int from = *wrongregular.begin();
            int to = *freeexample.begin();
            wrongregular.erase(wrongregular.begin());
            freeexample.erase(freeexample.begin());
            freeregular.insert(from);
            examples.erase(to_string(from));
            res.pb("move " + to_string(from) + " " + to_string(to));
        }

        while (!freeregular.empty() && !wrongexample.empty()) {
            int from = *wrongexample.begin();
            int to = *freeregular.begin();
            wrongexample.erase(wrongexample.begin());
            freeregular.erase(freeregular.begin());
            freeexample.insert(from);
            regular.erase(to_string(from));
            res.pb("move " + to_string(from) + " " + to_string(to));
        }
    }

    if (!wrongexample.empty()) {
        int from = *wrongregular.begin();
        res.pb("move " + to_string(from) + " " + to_string(n + 1));
        wrongregular.erase(from);
        freeregular.insert(from);
        examples.erase(to_string(from));
        examples.insert(to_string(n + 1));

        while (!wrongexample.empty()) {
            int from1 = *wrongexample.begin();
            res.pb("move " + to_string(from1) + " " + to_string(from));
            wrongexample.erase(from1);
            freeexample.insert(from1);
            freeregular.erase(from);
            regular.erase(to_string(from1));

            if (!wrongregular.empty()) {
                int from2 = *wrongregular.begin();
                res.pb("move " + to_string(from2) + " " + to_string(from1));
                wrongregular.erase(from2);
                freeregular.insert(from2);
                freeexample.erase(from1);
                examples.erase(to_string(from2));
                from = from2;
            }
        }
    }

    while (!examples.empty()) {
        res.pb("move " + *examples.begin() + " " + to_string(*freeexample.begin()));
        examples.erase(examples.begin());
        freeexample.erase(freeexample.begin());
    }

    while (!regular.empty()) {
        res.pb("move " + *regular.begin() + " " + to_string(*freeregular.begin()));
        regular.erase(regular.begin());
        freeregular.erase(freeregular.begin());
    }

    cout << res.size() << endl;
    for (string s : res) {
        cout << s << endl;
    }

    return 0;
}