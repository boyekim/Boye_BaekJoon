#include <iostream>
#include <queue>

using namespace std;

int n, m; //m==가로 n==세로
int map[101][101];
int cnt[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            cnt[i][j] = 2e9;
    }
}

void bfs() {
    int i;
    queue<pair<int, int>> q;
    q.push({1, 1});
    cnt[1][1] = 0;
    while (!q.empty()) {
        int now_x, now_y, next_x, next_y;
        now_x = q.front().first;
        now_y = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            next_x = now_x + dx[i];
            next_y = now_y + dy[i];
            if (next_x <= 0 || next_x > m || next_y <= 0 || next_y > n)
                continue;
            if (map[next_y][next_x] == 1
                && cnt[next_y][next_x] > cnt[now_y][now_x] + 1) {
                q.push({next_x, next_y});
                cnt[next_y][next_x] = cnt[now_y][now_x] + 1;
            } else if (map[next_y][next_x] == 0
                       && cnt[next_y][next_x] > cnt[now_y][now_x]) {
                q.push({next_x, next_y});
                cnt[next_y][next_x] = cnt[now_y][now_x];
            }
        }
    }
}

int main() {
    int i, j;
    cin >> m >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            scanf("%1d", &map[i][j]);
    }
    init();
    bfs();
    cout << cnt[n][m];
    return 0;
}