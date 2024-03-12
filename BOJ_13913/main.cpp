#include <iostream>
#include <queue>
#include <stack>

#define INF 2e9

using namespace std;

int n, k;
int DP[100001], visited[100001], before[100001];

void init() {
    int i;
    for (i = 0; i <= 100000; i++) {
        DP[i] = INF;
    }
}

void road() {
    stack<int> s;
    s.push(k);
    int now = k;
    while (1) {
        if (now == n)
            break;
        int next = before[now];
        s.push(next);
        now = next;
    }
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
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
            cout << DP[now] << '\n';
            return;
        }
        if (visited[now] >= 3)
            continue;
        visited[now]++;
        if (now + 1 >= 0 && now + 1 <= 100000 && DP[now + 1] > DP[now] + 1) {
            DP[now + 1] = DP[now] + 1;
            q.push(now + 1);
            before[now + 1] = now;
        }
        if (now - 1 >= 0 && now - 1 <= 100000 && DP[now - 1] > DP[now] + 1) {
            DP[now - 1] = DP[now] + 1;
            q.push(now - 1);
            before[now - 1] = now;
        }
        if (now * 2 >= 0 && now * 2 <= 100000 && DP[now * 2] > DP[now] + 1) {
            DP[now * 2] = DP[now] + 1;
            q.push(now * 2);
            before[now * 2] = now;
        }
    }
}

int main() {
    cin >> n >> k;
    init();
    bfs();
    road();
    return 0;
}