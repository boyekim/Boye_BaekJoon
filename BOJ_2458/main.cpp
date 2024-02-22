#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int n, m;
int cost[501][501];

void init() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }
}

void floyd() {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main() {
    int i, j;
    int ans = 0;
    cin >> n >> m;
    init();
    for (i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        cost[node1][node2] = 1;
    }
    floyd();
    for (i = 1; i <= n; i++) {
        bool check = true;
        for (j = 1; j <= n; j++) {
            if (cost[i][j] == INF && cost[j][i] == INF) {
                check = false;
                break;
            }
        }
        if (check)
            ans++;
    }
    cout << ans;
    return 0;
}