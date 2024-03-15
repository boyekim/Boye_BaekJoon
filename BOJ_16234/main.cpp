#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int n, l, r;
int map[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[51][51];
bool check;

void bfs(int x, int y) {
    int i, now_x, now_y;
    vector<pair<int, int>> v;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    v.push_back({x, y});
    int sum = 0;
    while (!q.empty()) {
        now_x = q.front().first;
        now_y = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n
                || visited[next_y][next_x])
                continue;
            int diff = abs(map[next_y][next_x] - map[now_y][now_x]);
            if (l <= diff && diff <= r) {
                q.push({next_x, next_y});
                visited[next_y][next_x] = true;
                check = true;
                v.push_back({next_x, next_y});
            }
        }
    }
    int size = v.size();
    for (i = 0; i < size; i++) {
        now_x = v[i].first;
        now_y = v[i].second;
        sum += map[now_y][now_x];
    }
    int avg = sum / size;
    for (i = 0; i < size; i++) {
        now_x = v[i].first;
        now_y = v[i].second;
        map[now_y][now_x] = avg;
    }
}

int main() {
    int cnt = 0;
    cin >> n >> l >> r;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    while (1) {
        check = false;
        memset(visited, false, sizeof(visited));
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    bfs(j, i);
                }
            }
        }
        if (!check)
            break;
        cnt++;
    }
    cout << cnt;
    return 0;
}