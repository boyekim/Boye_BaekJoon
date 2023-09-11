#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int n, m;
int cost[101][101];

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
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }
}

int main() {
    int i, j;
    cin >> n >> m;
    init();
    for (i = 0; i < m; i++) {
        int start, end, c;
        cin >> start >> end >> c;
        if (cost[start][end] > c)
            cost[start][end] = c;
    }
    floyd();
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (cost[i][j] == INF)
                cost[i][j] = 0;
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}