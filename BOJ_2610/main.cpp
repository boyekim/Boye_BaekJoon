#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int n, m;

int parent[101], DP[101][101], relay[101], CEO[101];
priority_queue<int> pq;

void init() {
    int i, j;
    for (i = 1; i <= n; i++) {
        parent[i] = i;
        CEO[i] = i;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j)
                DP[i][j] = 0;
            else
                DP[i][j] = INF;
        }
    }
}

int findParent(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
}

void Union(int nodeA, int nodeB) {
    int parentA = findParent(nodeA);
    int parentB = findParent(nodeB);
    if (parentA != parentB) {
        parent[parentB] = parentA;
    }
}

void floyd() {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
            }
        }
    }
}

int main() {
    int i, j;
    cin >> n >> m;
    init();
    for (i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        DP[a][b] = 1;
        DP[b][a] = 1;
        Union(a, b);
    }

    floyd();

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j || DP[i][j] >= INF)
                continue;
            relay[i] = max(relay[i], DP[i][j]); //각 노드에서 다른 트리 멤버들한테까지 가는 의사전달경로 중 최대 저장
        }
    }

    for (i = 1; i <= n; i++) {
        int tmp = findParent(i);
        int cmp = CEO[tmp];
        if (relay[cmp] > relay[i]) {
            CEO[tmp] = i; //가장 거리 작은 애로 대표 갱신
        }
    }

    for (i = 1; i <= n; i++) {
        if (parent[i] == i) {
            pq.push(-CEO[i]);
        }
    }
    cout << pq.size() << '\n';
    while (!pq.empty()) {
        cout << -pq.top() << '\n';
        pq.pop();
    }

    return 0;
}