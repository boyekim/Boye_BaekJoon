#include <iostream>
#include <queue>

using namespace std;

int k, w, h; //w==가로(x) h==세로(y)
int map[201][201];
int dx[12] = {-2, -1, 1, 2, -2, -1, 1, 2, -1, 1, 0, 0};
int dy[12] = {-1, -2, -2, -1, 1, 2, 2, 1, 0, 0, -1, 1};
bool visited[201][201][31];

void bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    visited[0][0][0] = true;
    q.push({{0, 0},
            {0, 0}}); //칸이동 횟수, 능력 사용 횟수, x,y
    while (!q.empty()) {
        int next_x, next_y;
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first.first;
        int abil = q.front().first.second;
        q.pop();
        if (x == w - 1 && y == h - 1) {
            cout << cnt << '\n';
            return;
        }
        if (abil < k) {
            for (int i = 0; i < 8; i++) {
                next_x = x + dx[i];
                next_y = y + dy[i];
                if (visited[next_y][next_x][abil + 1] || map[next_y][next_x] == 1
                    || next_x < 0 || next_x >= w || next_y < 0 || next_y >= h)
                    continue;
                visited[next_y][next_x][abil + 1] = true;
                q.push({{cnt + 1, abil + 1},
                        {next_x,  next_y}});
            }
        }
        for (int i = 8; i < 12; i++) {
            next_x = x + dx[i];
            next_y = y + dy[i];
            if (visited[next_y][next_x][abil] || map[next_y][next_x] == 1
                || next_x < 0 || next_x >= w || next_y < 0 || next_y >= h)
                continue;
            visited[next_y][next_x][abil] = true;
            q.push({{cnt + 1, abil},
                    {next_x,  next_y}});
        }
    }
    cout << -1 << '\n';
}

int main() {
    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }
    bfs();
    return 0;
}