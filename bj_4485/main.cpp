#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2e9

using namespace std;

int n, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[126][126];
int dist[126][126];

void init() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
    }
}

void input() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
}

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(0, 0))); //맨 앞이 현재 cost
    dist[0][0] = map[0][0];
    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        pq.pop();
        if (now_x == n - 1 && now_y == n - 1) {
            cout << "Problem " << cnt << ": " << dist[now_y][now_x] << '\n';
            return;
        }
        if (now_cost > dist[now_y][now_x])
            continue;
        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
                continue;
            int next_cost = dist[now_y][now_x] + map[next_y][next_x];
            if (next_cost < dist[next_y][next_x]) {
                dist[next_y][next_x] = next_cost;
                pq.push(make_pair(-next_cost, make_pair(next_x, next_y)));
            }
        }
    }
}

int main() {
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        cnt++;
        init();
        input();
        dijkstra();
    }
    return 0;
}