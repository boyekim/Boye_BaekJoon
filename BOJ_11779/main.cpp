#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>

#define INF 2e9

using namespace std;

vector<pair<int, int>> v[1001];
int dist[1001], road[1001];
int n, m, first, last;

void init() {
    int i;
    for (i = 0; i <= n; i++) {
        dist[i] = INF;
    }
}

void dijkstra() {
    int i;
    priority_queue<pair<int, int>> pq;
    dist[first] = 0;
    pq.push({0, first});
    while (!pq.empty()) {
        int nowCity = pq.top().second;
        int nowCost = -pq.top().first;
        pq.pop();
        int size = v[nowCity].size();
        if (dist[nowCity] < nowCost) {
            continue;
        }
        for (i = 0; i < size; i++) {
            int nextCity = v[nowCity][i].first;
            int nextCost = v[nowCity][i].second;
            if (nowCost + nextCost < dist[nextCity]) {
                dist[nextCity] = nowCost + nextCost;
                road[nextCity] = nowCity;
                pq.push({-dist[nextCity], nextCity});
            }
        }
    }
}

void print() {
    int city = last;
    int cnt = 1;
    stack<int> s;
    while (city != first) {
        cnt++;
        s.push(city);
        city = road[city];
    }
    s.push(first);
    cout << cnt << '\n';
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}

int main() {
    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({end, cost});
    }
    init();
    cin >> first >> last;
    dijkstra();
    cout << dist[last] << '\n';
    print();
    return 0;
}