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

struct Node {
    ll x, y, r;
    vector<Node*> children;
    Node(ll xx, ll yy, ll rr) : x(xx), y(yy), r(rr){};
};

int gao(Node* node1, Node* node2) {
    ll dist = (node1->x - node2->x) * (node1->x - node2->x) + (node1->y - node2->y) * (node1->y - node2->y);
    if (dist < (node1->r + node2->r) * (node1->r + node2->r)) {
        if (node1->r < node2->r) {// 1 in 2
            return 0;
        } else return 1;//2 in 1
    } else {
        return 2;//disjoint
    }
}

int n;
vector<Node*> nodes;

void merge(vector<Node*>& roots, Node* nod) {
    for (int i = 0; i < roots.size(); ++i) {
        int tmp = gao(roots[i], nod);
        if (tmp == 0) {
            nod->children.push_back(roots[i]);
            roots[i] = nod;
            for (int j = i + 1; j < roots.size(); ++j) {
                if (gao(roots[i], roots[j]) == 1) {
                    roots[i]->children.push_back(roots[j]);
                    roots.erase(roots.begin() + j);
                    --j;
                }
            }
            return;
        } else if (tmp == 1) {
            merge(roots[i]->children, nod);
            return;
        }
    }
    roots.push_back(nod);
}

pair<ll, ll> calu(Node* node) {
    if (node->children.size() == 0) {
        return {0, node->r * node->r};
    } else {
        ll tmp = 0;
        for (Node* child : node->children) {
            pair<ll, ll> sub = calu(child);
            tmp += sub.second - sub.first;
        }
        return {tmp, node->r * node->r};
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll x, y, r;
        cin >> x >> y >> r;
        Node* nod = new Node(x, y, r);
        merge(nodes, nod);
    }
    ll res = 0;
    for (Node* node : nodes) {
        pair<ll, ll> sub = calu(node);
        res += sub.first + sub.second;
    }
    printf("%.9lf", PI * res);

    return 0;
}