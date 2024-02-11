#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
using namespace std;

int n, m;
int parent[MAX];
vector<pair<int, pair<int, int>>> v;
vector<int> mst;

void init() {
    int i;
    for (i = 1; i <= n; i++)
        parent[i] = i;
}

void input() {
    int i, node1, node2, cost;
    for (i = 0; i < m; i++) {
        cin >> node1 >> node2 >> cost;
        v.push_back({cost, {node1, node2}});
    }
    sort(v.begin(), v.end());
}

int findParent(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
}

void Union(int node1, int node2) {
    node1 = findParent(node1);
    node2 = findParent(node2);
    if (node1 != node2) {
        parent[node1] = node2;
    }
}

void kruskal() {
    int i;
    for (i = 0; i < m; i++) {
        int node1 = v[i].second.first;
        int node2 = v[i].second.second;
        int cost = v[i].first;
        if (findParent(node1) != findParent(node2)) {
            Union(node1, node2);
            mst.push_back(cost);
        }
    }
}

int main() {
    int sum = 0, i;
    cin >> n >> m;
    init();
    input();
    kruskal();
    sort(mst.begin(), mst.end());
    for (i = 0; i < mst.size() - 1; i++) {
        sum += mst[i];
    }
    cout << sum;
    return 0;
}