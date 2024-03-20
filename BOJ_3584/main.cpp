#include <iostream>
#include <cstring>

using namespace std;

int t, n, node1, node2;
int parent[10001];
bool visited[10001];

void init() {
    int i;
    for (i = 1; i <= n; i++) {
        parent[i] = i;
    }
    memset(visited, false, sizeof(visited));
}

void input() {
    int i;
    for (i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;
        parent[c] = p;
    }
    cin >> node1 >> node2;
}

void findRoute(int node) {
    visited[node] = true;
    if (parent[node] == node) {
        return;
    }
    findRoute(parent[node]);
}

void solve() {
    int i;
    findRoute(node1);
    int node = node2;
    while (1) {
        if (parent[node] == node) {
            cout << node << '\n';
            return;
        }
        if (visited[node]) {
            cout << node << '\n';
            return;
        }
        node = parent[node];
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        input();
        solve();
    }
    return 0;
}