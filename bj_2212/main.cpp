#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, ans;
vector<int> v;
priority_queue<int> pq;

void saveGap() {
    int i;
    for (i = 1; i < n; i++) {
        pq.push(v[i] - v[i - 1]);
    }
}

void solve() {
    int i;
    if (k > n)
        return;
    for (i = 0; i < k - 1; i++)
        pq.pop();
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
}

int main() {
    int i;
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    saveGap();
    solve();
    cout << ans;
    return 0;
}