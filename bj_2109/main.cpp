#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, idx;
int day[10001];
priority_queue<pair<int, int>> pq; //처음에 돈을 기준으로 정렬

void solve() {
    int i;
    while (!pq.empty()) {
        int price, dead_line;
        price = pq.top().first;
        dead_line = pq.top().second;
        pq.pop();
        for (i = dead_line; i > 0; i--) {
            if (day[i] == 0) {
                day[i] = max(day[i], price);
                break;
            }
        }
    }
}

int sum() {
    int i, ans = 0;
    for (i = 1; i <= idx; i++) {
        ans += day[i];
    }
    return ans;
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        pq.push({p, d});
        idx = max(idx, d);
    }
    solve();
    cout << sum();
    return 0;
}