#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q, water;
int r, c, sec, beav_x, beav_y;
char map[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    int i, j, x, y, next_x, next_y;
    while (!q.empty()) {
        int water_x, water_y;
        int sizeWater = water.size();
        for (i = 0; i < sizeWater; i++) {
            water_x = water.front().first;
            water_y = water.front().second;
            water.pop();
            for (j = 0; j < 4; j++) {
                int water_next_x = water_x + dx[j];
                int water_next_y = water_y + dy[j];
                if (water_next_x < 0 || water_next_x >= c || water_next_y < 0 || water_next_y >= r)
                    continue;
                if (map[water_next_y][water_next_x] == '.') {
                    map[water_next_y][water_next_x] = '*';
                    water.push({water_next_x, water_next_y});
                }
            }
        }
        int sizeHed = q.size();
        for (i = 0; i < sizeHed; i++) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (j = 0; j < 4; j++) {
                next_x = x + dx[j];
                next_y = y + dy[j];
                if (next_x == beav_x && next_y == beav_y) {
                    cout << sec + 1;
                    return;
                }
                if (next_x < 0 || next_x >= c || next_y < 0 || next_y >= r)
                    continue;
                if (map[next_y][next_x] == '.') {
                    q.push({next_x, next_y});
                    map[next_y][next_x] = 'S';
                }
            }
        }
        sec++;
    }
    cout << "KAKTUS";
}

int main() {
    int i, j;
    cin >> r >> c;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                q.push({j, i});
            } else if (map[i][j] == '*') {
                water.push({j, i});
            } else if (map[i][j] == 'D') {
                beav_x = j;
                beav_y = i;
            }
        }
    }
    bfs();
    return 0;
}