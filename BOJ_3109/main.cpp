#include <iostream>

using namespace std;

int r, c, cnt; //r이 세로 c가 가로
int map[10001][501];
int dx[3] = {1, 1, 1};//오른쪽 위 -> 오른쪽 -> 오른쪽 아래 순서대로
int dy[3] = {-1, 0, 1};
bool visited[10001][501];
bool check;

void input() {
    int i, j;
    cin >> r >> c;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            char tmp;
            cin >> tmp;
            map[i][j] = (tmp == '.' ? 0 : 1); //건물은 1, 즉 이동 불가
        }
    }
}

void dfs(int x, int y) {
    int i;
    if (x == c - 1) {
        cnt++;
        check = true;
        return;
    }
    for (i = 0; i < 3; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (visited[next_y][next_x] || map[next_y][next_x] == 1
            || next_x < 0 || next_x >= c || next_y < 0 || next_y >= r) {
            continue;
        }
        visited[next_y][next_x] = true;
        dfs(next_x, next_y);
        if (check)
            break;
    }
}

int main() {
    int i;
    input();
    for (i = 0; i < r; i++) {
        if (map[i][0] == 0 && !visited[i][0]) {
            visited[i][0] = true;
            check = false;
            dfs(0, i);
        }
    }
    cout << cnt;
    return 0;
}