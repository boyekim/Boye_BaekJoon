#include <iostream>
#include <queue>

#define INF 987654321

using namespace std;

int n;
int map[51][51];
int cnt[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cnt[i][j] = INF;
    }
}

void bfs() {
    int i;
    queue<pair<int, int>> q;
    q.push({0, 0});
    cnt[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
                continue;
            if (map[next_y][next_x] == 1) {
                if (cnt[next_y][next_x] > cnt[y][x]) {
                    cnt[next_y][next_x] = cnt[y][x];
                    q.push({next_x, next_y});
                }
                continue;
            }
            if (cnt[next_y][next_x] > cnt[y][x] + 1) {
                cnt[next_y][next_x] = cnt[y][x] + 1;
                q.push({next_x, next_y});
            }
        }
    }
    cout << cnt[n - 1][n - 1];
}

int main() {
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    init();
    bfs();
    return 0;
}