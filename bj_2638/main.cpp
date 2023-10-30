#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int cheese[101][101];
int cnt[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[101][101];
queue<pair<int, int>> side;

void init() {
    int i, j;
    memset(visited, false, sizeof(visited));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cnt[i][j] = 0;
        }
    }
}

void bfs() {
    queue<pair<int, int>> q;
    int i;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (visited[next_y][next_x] || next_x < 0 || next_x >= m
                || next_y < 0 || next_y >= n)
                continue;
            if (cheese[next_y][next_x] == 1) { //1은 q에 삽입하지 않음-> 안에 있는 0은 고려하지 않음
                cnt[next_y][next_x]++;
                if (cnt[next_y][next_x] == 2) {
                    side.push({next_x, next_y});
                }
            } else {
                q.push({next_x, next_y});
                visited[next_y][next_x] = true;
            }
        }
    }
}

void melting() {
    while (!side.empty()) {
        int x, y;
        x = side.front().first;
        y = side.front().second;
        side.pop();
        cheese[y][x] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, j;
    int ans = 0;
    cin >> n >> m; //n이 세로 m이 가로
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> cheese[i][j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            init();
            bfs();
            if (side.size() == 0) {
                cout << ans;
                return 0;
            }
            melting();
            ans++;
        }
    }
}