#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, ans = 1;
vector<pair<int, int>> v[102][102];
int light[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[102][102];

void bfs() {
    int i, size;
    queue<pair<int, int>> q;
    q.push({1, 1}); //(1,1)에서 시작
    light[1][1] = 1;
    visited[1][1] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        size = v[y][x].size();
        for (i = 0; i < size; i++) {
            int tmp_x = v[y][x][i].first;
            int tmp_y = v[y][x][i].second;
            if (light[tmp_y][tmp_x] == 1)
                continue;
            light[tmp_y][tmp_x] = 1; //불 켜기
            ans++;
            memset(visited, false, sizeof(visited));
        }
        for (i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x <= 0 || next_x > n || next_y <= 0 || next_y > n
                || light[next_y][next_x] == 0 || visited[next_y][next_x]) //불 안켜져있으면
                continue;
            visited[next_y][next_x] = true;
            q.push({next_x, next_y});
        }
    }
}

int main() {
    int i, m;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[y][x].push_back({a, b});
    }
    bfs();
    cout << ans;
    return 0;
}