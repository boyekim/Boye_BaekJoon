#include <iostream>

using namespace std;
int n, m, ans;
int dx[4] = {-1, 1, 0, 0}; //(-1,0),(1,0),(0,-1),(0,1)
int dy[4] = {0, 0, -1, 1}; //왼 , 오 , 위 , 아래
int map[1001][1001];
bool visited[1001][1001];
int safe[1001][1001];

void dfs(int x, int y, int cnt) {
    if (visited[y][x]) {
        if (safe[y][x] == cnt) {
            ans++;
        }
        return;
    }
    visited[y][x] = true;
    int tmp = map[y][x];
    int next_x = x + dx[tmp];
    int next_y = y + dy[tmp];
    safe[y][x] = cnt;
    dfs(next_x, next_y, cnt);
}

int main() {
    int i, j;
    char c;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> c;
            if (c == 'D') {
                map[i][j] = 3;
            } else if (c == 'L') {
                map[i][j] = 0;
            } else if (c == 'R') {
                map[i][j] = 1;
            } else if (c == 'U') {
                map[i][j] = 2;
            }
        }
    }

    int count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(j, i, ++count);
            }
        }
    }

    cout << ans;
    return 0;
}