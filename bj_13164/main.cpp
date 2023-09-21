#include <iostream>
#include <queue>

using namespace std;

int n, k;
int student[300001];
priority_queue<int> pq;

void saveGap() {
    int i;
    for (i = 1; i < n; i++) {
        int tmp = student[i] - student[i - 1];
        pq.push(tmp);
    }
}

void solve() {
    int result = 0, cnt = 0;
    while (cnt != (k - 1)) {
        pq.pop();
        cnt++;
    }
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }
    cout << result;
}

int main() {
    int i;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> student[i];

    saveGap();
    solve();
    return 0;
}