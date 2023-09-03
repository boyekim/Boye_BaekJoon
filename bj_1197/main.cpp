#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e, ans;
int parent[100001];
vector<pair<int, pair<int, int>>> graph;

void init() {
    int i;
    for (i = 1; i <= v; i++)
        parent[i] = i;
}

int findRoot(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = findRoot(parent[a]);
}

void Union(int a, int b) {
    int node1 = findRoot(a);
    int node2 = findRoot(b);
    parent[node2] = node1;
}

void kruskal() {
    int i;
    for (i = 0; i < e; i++) {
        int node1, node2;
        node1 = findRoot(graph[i].second.first);
        node2 = findRoot(graph[i].second.second);
        if (node1 == node2)
            continue;
        Union(node1, node2);
        ans += graph[i].first;
    }
}

int main() {
    int i;
    cin >> v >> e;
    for (i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    sort(graph.begin(), graph.end());
    init();
    kruskal();
    cout << ans;
    return 0;
}