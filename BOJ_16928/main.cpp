#include <iostream>
#include <queue>

#define INF 2e9

using namespace std;

int n, m;
int ladder[101], snake[101], cnt[101];

void input() {
    int i, from, to;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> from >> to;
        ladder[from] = to;
    }
    for (i = 0; i < m; i++) {
        cin >> from >> to;
        snake[from] = to;
    }
    for (i = 1; i <= 100; i++)
        cnt[i] = INF;
}

void solve() {
    int i, now, next;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    cnt[1] = 0;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (i = 1; i <= 6; i++) {
            next = now + i;
            if (next > 100)
                continue;
            if (ladder[next] != 0) {
                next = ladder[next];
            }
            if (snake[next] != 0) {
                next = snake[next];
            }
            if (cnt[next] > cnt[now] + 1) {
                q.push(next);
                cnt[next] = cnt[now] + 1;
            }
        }
    }
    cout << cnt[100];
}

int main() {
    input();
    solve();
    return 0;
}