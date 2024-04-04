#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int t, n, homeX, homeY, fesX, fesY;
vector<pair<int, int>> v;
bool visited[101];

void input() {
    int i, x, y;
    v.clear();
    memset(visited, false, sizeof(visited));
    cin >> n;
    cin >> homeX >> homeY;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    cin >> fesX >> fesY;
}

void bfs() {
    int i;
    queue<pair<int, int>> q;
    q.push({homeX, homeY});
    while (!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        if (abs(nowX - fesX) + abs(nowY - fesY) <= 1000) {
            cout << "happy" << '\n';
            return;
        }
        for (i = 0; i < n; i++) {
            int nextX = v[i].first;
            int nextY = v[i].second;
            if (abs(nextX - nowX) + abs(nextY - nowY) > 1000 || visited[i])
                continue;
            visited[i] = true;
            q.push({nextX, nextY});

        }
    }
    cout << "sad" << '\n';
}

int main() {
    cin >> t;
    while (t--) {
        input();
        bfs();
    }
}