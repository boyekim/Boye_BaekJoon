#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;
int n, cnt;
long long ans;
int parent[1001];

void input() {
    int i, j, cost;
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> cost;
            if (i >= j)
                continue;
            pq.push({-cost, {i, j}});
        }
    }
}

void init() {
    int i;
    for (i = 1; i <= n; i++)
        parent[i] = i;
}

int findRoot(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findRoot(parent[node]);
}

void Union(int node1, int node2) {
    node1 = findRoot(node1);
    node2 = findRoot(node2);
    if (node1 != node2)
        parent[node1] = node2;
}

void kruskal() {
    while (!pq.empty()) {
        if (cnt == n - 1) {
            return;
        }
        int cost = -pq.top().first;
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        pq.pop();

        int p1 = findRoot(node1);
        int p2 = findRoot(node2);
        if (p1 == p2) {
            continue;
        }

        Union(node1, node2);
        ans += cost;
        cnt++;
    }
}

int main() {
    input();
    init();
    kruskal();
    cout << ans;
    return 0;
}