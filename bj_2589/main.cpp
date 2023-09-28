#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int r, c, ans, result;
char map[51][51];
int cnt[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[51][51];

void init() {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cnt[i][j] = 2e9;
        }
    }
    memset(visited, false, sizeof(visited));
    ans = 0;
}

void findMax() {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (cnt[i][j] != 2e9) {
                ans = max(ans, cnt[i][j]);
            }
        }
    }
}

void bfs(int x, int y) {
    int i;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    cnt[y][x] = 0;
    while (!q.empty()) {
        int now_x, now_y, next_x, next_y;
        now_x = q.front().first;
        now_y = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            next_x = now_x + dx[i];
            next_y = now_y + dy[i];
            if (visited[next_y][next_x] || map[next_y][next_x] == 'W'
                || next_x < 0 || next_x >= c || next_y < 0 || next_y >= r)
                continue;
            q.push({next_x, next_y});
            visited[next_y][next_x] = true;
            cnt[next_y][next_x] = min(cnt[next_y][next_x], cnt[now_y][now_x] + 1);
        }
    }
}

int main() {
    int i, j;

    cin >> r >> c;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (map[i][j] == 'L') {
                init();
                bfs(j, i);
                findMax();
                result = max(result, ans);
            }
        }
    }
    cout << result;
    return 0;
}