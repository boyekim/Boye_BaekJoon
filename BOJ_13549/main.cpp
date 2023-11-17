#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2e9

using namespace std;

int n, k;
int DP[100001], visited[100001];

void init() {
    int i;
    for (i = 0; i <= 100000; i++) {
        DP[i] = INF;
    }
}

void bfs() {
    queue<int> q;
    DP[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == k) {
            cout << DP[now];
            return;
        }
        if (visited[now] >= 3)
            continue;
        visited[now]++;
        if (now + 1 >= 0 && now + 1 <= 100000) {
            DP[now + 1] = min(DP[now + 1], DP[now] + 1);
            q.push(now + 1);
        }
        if (now - 1 >= 0 && now - 1 <= 100000) {
            DP[now - 1] = min(DP[now - 1], DP[now] + 1);
            q.push(now - 1);
        }
        if (now * 2 >= 0 && now * 2 <= 100000) {
            DP[now * 2] = min(DP[now * 2], DP[now]);
            q.push(now * 2);
        }
    }
}

int main() {
    cin >> n >> k;
    init();
    bfs();
    return 0;
}