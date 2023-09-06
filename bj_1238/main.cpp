#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 2e9

using namespace std;

int n, m, x, ans; //x에서 종료
int dist[1001];
vector<pair<int, int>> v[1001];

void init() {
    int i;
    for (i = 1; i <= n; i++) {
        dist[i] = INF;
    }
}

void dijkstra(int start) {
    int i;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int now_node = pq.top().second;
        int now_cost = -pq.top().first;
        pq.pop();
        int size = v[now_node].size();
        if (now_cost > dist[now_node])
            continue;
        for (i = 0; i < size; i++) {
            int next_node = v[now_node][i].first;
            int next_cost = v[now_node][i].second;
            if (next_cost + dist[now_node] < dist[next_node]) {
                dist[next_node] = next_cost + dist[now_node];
                pq.push({-dist[next_node], next_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, start, end, cost;
    cin >> n >> m >> x;
    for (i = 0; i < m; i++) {
        cin >> start >> end >> cost;
        v[start].push_back({end, cost});
    }
    for (i = 1; i <= n; i++) {
        int sum = 0;
        init();
        dijkstra(i);
        sum += dist[x];
        init();
        dijkstra(x);
        sum += dist[i];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}