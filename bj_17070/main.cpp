#include <iostream>

using namespace std;

int n, ans;
int house[17][17];
int dx[3] = {1, 1, 0}; //(1,0),(1,1),(0,1)
int dy[3] = {0, 1, 1};

//끝점만 생각해도될듯. 앞 점은 어차피 처음의 끝 점과 동일해짐 -> 범위를 벗어날 일이 없음

void dfs(int x, int y, int check) {//check : 가로==0, 세로==2, 대각선==1
    int i, next_x, next_y;
    if (x == n - 1 && y == n - 1) {
        ans++;
        return;
    }
    if (check == 0) {
        for (i = 0; i < 2; i++) {
            next_x = x + dx[i];
            next_y = y + dy[i];
            if (next_x >= n || next_y >= n || house[next_y][next_x] == 1)
                continue;
            if (i == 1) {
                if (house[next_y - 1][next_x] == 1 ||
                    house[next_y][next_x - 1] == 1)
                    continue;
            }
            dfs(next_x, next_y, i);
        }
    } else if (check == 1) { //대각선으로 놓여있는
        for (i = 0; i < 3; i++) {
            next_x = x + dx[i];
            next_y = y + dy[i];
            if (next_x >= n || next_y >= n || house[next_y][next_x] == 1)
                continue;
            if (i == 1) {
                if (house[next_y - 1][next_x] == 1 ||
                    house[next_y][next_x - 1] == 1)
                    continue;
            }
            dfs(next_x, next_y, i);
        }
    } else if (check == 2) { //세로로 놓여있는
        for (i = 1; i < 3; i++) {
            next_x = x + dx[i];
            next_y = y + dy[i];
            if (next_x >= n || next_y >= n || house[next_y][next_x] == 1)
                continue;
            if (i == 1) {
                if (house[next_y - 1][next_x] == 1 ||
                    house[next_y][next_x - 1] == 1)
                    continue;
            }
            dfs(next_x, next_y, i);
        }
    }
}

int main() {
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cin >> house[i][j];
    }
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}