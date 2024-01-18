#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, sum, cnt;
int gender[1001], parent[1001];
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
    parent[nodeA] = nodeB;
}

void kruskal() {
    int i;
    for (i = 0; i < v.size(); i++) {
        int nowCost = v[i].first;
        int nodeA = v[i].second.first;
        int nodeB = v[i].second.second;
        if (findParent(nodeA) == findParent(nodeB) || gender[nodeA] == gender[nodeB])
            continue;
        Union(nodeA, nodeB);
        sum += nowCost;
        cnt++;
        if (cnt == n - 1) {
            cout << sum << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

void input() {
    int i;
    for (i = 1; i <= n; i++) {
        char tmp; //남자가 1, 여자가 2
        cin >> tmp;
        if (tmp == 'M')
            gender[i] = 1;
        else
            gender[i] = 2;
    }
    for (i = 0; i < m; i++) {
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost;
        v.push_back({cost, {node1, node2}});
    }
    sort(v.begin(), v.end());
}

int main() {
    cin >> n >> m;
    init();
    input();
    kruskal();
    return 0;
}