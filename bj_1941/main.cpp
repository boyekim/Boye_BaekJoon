#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
char stu[6][6];
int ans;
bool visited[26];

bool find_count() {
    int i;
    int cnt = 0;
    for (i = 0; i < 25; i++) {
        if (visited[i]) {
            if (stu[i / 5][i % 5] == 'S')
                cnt++;
        }
    }
    if (cnt >= 4)
        return true;
    return false;
}

bool bfs() {
    queue<pair<int, int>> q;
    int i;
    bool queue_visited[6][6];
    bool check[6][6];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    memset(check, false, sizeof(check));
    memset(queue_visited, false, sizeof(queue_visited));
    for (i = 0; i < 25; i++) {
        if (visited[i]) {
            q.push({i % 5, i / 5});
            queue_visited[i / 5][i % 5] = true;
            break;
        }
    }
    for (i = 0; i < 25; i++) {
        if (visited[i]) {
            check[i / 5][i % 5] = true;
        }
    }
    int cnt = 1;
    while (!q.empty()) {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (cnt == 7) {
            return true;
        }
        for (i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5)
                continue;
            if (queue_visited[next_y][next_x])
                continue;
            if (check[next_y][next_x]) {
                q.push({next_x, next_y});
                queue_visited[next_y][next_x] = true;
                cnt++;
            }
        }
    }
    return false;
}

void dfs(int idx, int cnt) {
    int i;
    if (cnt == 7) {
        if (find_count()) {
            if (bfs())
                ans++;
        }
        return;
    }
    for (i = idx; i < 25; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cin >> stu[i][j];
        }
    }

    dfs(0, 0);
    cout << ans;
    return 0;
}