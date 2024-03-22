#include <iostream>
#include <vector>
#include <queue>

#define INF 2e9

using namespace std;

int t, n, d, c, a, b, s;
vector<pair<int, int>> v[10001];
int DP[10001];

void init() {
    int i;
    for (i = 0; i <= n; i++) {
        DP[i] = INF;
        v[i].clear();
    }
}

void input() {
    int i;
    for (i = 0; i < d; i++) {
        cin >> a >> b >> s;
        v[b].push_back({a, s});
    }
}

void dijkstra() {
    int cnt = 0;
    int i, now, ans_cost=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, c});
    DP[c] = 0;
    while (!pq.empty()) {
        now = pq.top().second;
        int now_cost = -pq.top().first;
        pq.pop();
        int size = v[now].size();
        if (now_cost > DP[now])
            continue;
        for (i = 0; i < size; i++) {
            int next = v[now][i].first;
            int next_cost = v[now][i].second;
            if (DP[next] > now_cost + next_cost) {
                DP[next] = now_cost + next_cost;
                pq.push({-DP[next], next});
            }
        }
    }
    for (i = 1; i <= n; i++) {
        if (DP[i] == INF)
            continue;
        cnt++;
        if (ans_cost < DP[i]) {
            ans_cost = DP[i];
        }
    }
    cout << cnt << ' ' << ans_cost << '\n';
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> d >> c;
        init();
        input();
        dijkstra();
    }
    return 0;
}