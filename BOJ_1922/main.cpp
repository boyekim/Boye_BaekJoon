#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans;
int parent[1001];
vector<pair<int, pair<int, int>>> v;

void init() {
    int i;
    for (i = 1; i <= n; i++)
        parent[i] = i;
}

int findParent(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
}

void Union(int nodeA, int nodeB) {
    nodeA = findParent(nodeA);
    nodeB = findParent(nodeB);
    if (nodeA != nodeB)
        parent[nodeB] = nodeA;
}

void kruskal() {
    int i;
    for (i = 0; i < m; i++) {
        int nowCost = v[i].first;
        int com1 = v[i].second.first;
        int com2 = v[i].second.second;
        if (findParent(com1) == findParent(com2))
            continue;
        Union(com1, com2);
        ans += nowCost;
    }
}

int main() {
    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        int com1, com2, cost;
        cin >> com1 >> com2 >> cost;
        v.push_back({cost, {com1, com2}});
    }
    sort(v.begin(), v.end());
    init();
    kruskal();
    cout << ans;
    return 0;
}