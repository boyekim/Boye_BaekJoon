#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>> pq;
int assignment[1001];
int day, n;

void solve() {
    int i;
    for (i = 0; i < n; i++) {
        int dead = pq.top().second;
        int score = pq.top().first;
        pq.pop();
        while (assignment[dead] != 0 && dead > 0) {
            dead--;
        }
        assignment[dead] = score;
    }
}

int main() {
    int i, ans = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        int d, w;
        cin >> d >> w;
        day = max(day, d);
        pq.push({w, d});
    }
    solve();
    for (i = 1; i <= day; i++) {
        ans += assignment[i];
    }
    cout << ans;
    return 0;
}