#include <iostream>

using namespace std;

int n, m;
int idx = 1;
int Map[1001][1001], tmp[1001][1001], area[1000000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[1001][1001], areaVisited[1000000];

void input() {
    int i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%1d", &Map[i][j]);
        }
    }
}

int dfs(int x, int y) {
    int i;
    int size = 1;
    for (i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n
            || visited[next_y][next_x] || Map[next_y][next_x] == 1) {
            continue;
        }
        visited[next_y][next_x] = true;
        tmp[next_y][next_x] = idx;
        size += dfs(next_x, next_y);
    }
    return size;
}

void solve() { //0이라면 그대로 0 출력하고 1(벽) 이라면 주변의 0크기를 더해서 출력한다.
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int sum = 0;
            if (Map[i][j] == 0) {
                cout << 0;
            } else {
                for (k = 0; k < 4; k++) {
                    int next_x = j + dx[k];
                    int next_y = i + dy[k];
                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || Map[next_y][next_x] == 1)
                        continue;
                    int now_idx = tmp[next_y][next_x];
                    if (areaVisited[now_idx])
                        continue;
                    areaVisited[now_idx] = true;
                    sum += area[now_idx];
                }
                cout << (sum + 1) % 10;

                //방문했던 곳 다시 false로 되돌려놓기
                for (k = 0; k < 4; k++) {
                    int next_x = j + dx[k];
                    int next_y = i + dy[k];
                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || Map[next_y][next_x] == 1)
                        continue;
                    int now_idx = tmp[next_y][next_x];
                    areaVisited[now_idx] = false;
                }
            }
        }
        cout << '\n';
    }
}

int main() {
    int i, j;
    input();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (Map[i][j] == 0 && !visited[i][j]) {
                visited[i][j] = true;
                tmp[i][j] = idx;
                int size = dfs(j, i);
                area[idx] = size;
                idx++;
            }
        }
    }
    solve();
    return 0;
}