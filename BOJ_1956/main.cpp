#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int v, e;
int map[401][401];

void init() {
    int i, j;
    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            if (i == j) {
                map[i][j] = 0;
            } else {
                map[i][j] = INF;
            }
        }
    }
}

void input() {
    int i, node1, node2, cost;
    for (i = 0; i < e; i++) {
        cin >> node1 >> node2 >> cost;
        map[node1][node2] = cost;
    }
}

void floyd() {
    int i, j, k;
    for (k = 1; k <= v; k++) {
        for (i = 1; i <= v; i++) {
            for (j = 1; j <= v; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
}

int main() {
    int ans = INF, i, j;
    cin >> v >> e;
    init();
    input();
    floyd();
    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            if (i == j)
                continue;
            ans = min(ans, map[i][j] + map[j][i]);
        }
    }
    if (ans >= INF) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}