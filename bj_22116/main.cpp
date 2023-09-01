#include <iostream>
#include <queue>
#include <cmath>

#define INF 2e9

using namespace std;

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int A[1001][1001];
int dist[1001][1001];

void init() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            dist[i][j] = INF;
    }
}

void dijkstra() {
    int i, now_x, now_y, now_cost, next_x, next_y, next_cost;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    //처음 비용은 0이고 0,0에서 시작
    dist[0][0] = 0;

    while (!pq.empty()) {
        now_cost = -pq.top().first;
        now_x = pq.top().second.first;
        now_y = pq.top().second.second;
        pq.pop();
        if (now_cost > dist[now_y][now_x])
            continue;
        for (i = 0; i < 4; i++) {
            next_x = now_x + dx[i];
            next_y = now_y + dy[i];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
                continue;
            next_cost = max(abs(A[now_y][now_x] - A[next_y][next_x]), now_cost);
            if (next_cost < dist[next_y][next_x]) {
                dist[next_y][next_x] = next_cost;
                pq.push(make_pair(-next_cost, make_pair(next_x, next_y)));
            }
        }
    }
}

int main() {
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    init();
    dijkstra();
    cout << dist[n - 1][n - 1];
    return 0;
}