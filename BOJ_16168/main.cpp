#include <iostream>
#include <vector>

using namespace std;

int v, e;
vector<int> graph[3001];
bool visited[3001];
int cnt[3001];

void input() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
        cnt[node1]++;
        cnt[node2]++;
    }
}

void dfs(int now) {
    int size = graph[now].size();
    for (int i = 0; i < size; i++) {
        int next = graph[now][i];
        if (visited[next])
            continue;
        visited[next] = true;
        dfs(next);
    }
}

int allDfs() {
    int result = 0;
    for (int i = 1; i <= v; i++) {
        if (visited[i])
            continue;
        result++;
        dfs(i);
    }
    return result;
}

int main() {
    input();
    int result = 0;
    if (allDfs() > 1) {
        cout << "NO" << '\n';
        return 0;
    }
    for (int i = 1; i <= e; i++) {
        if (cnt[i] % 2 == 1) {
            result++;
        }
    }
    if (result == 0 || result == 2) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}