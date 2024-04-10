#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> v[10001];
int sec[10001], deg[10001], DP[10001];

void input() {
    int i, j, num, bef;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> sec[i];
        cin >> num;
        deg[i] = num;
        for (j = 0; j < num; j++) {
            cin >> bef;
            v[bef].push_back(i);
        }
    }
}

void topology() {
    int i;
    queue<int> q;
    for (i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
        DP[i] = sec[i];
    }
    while (!q.empty()) {
        int now = q.front();
        int size = v[now].size();
        q.pop();
        for (i = 0; i < size; i++) {
            int next = v[now][i];
            deg[next]--;
            DP[next] = max(DP[now] + sec[next], DP[next]);
            if (deg[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main() {
    int i, ans = 0;
    input();
    topology();
    for (i = 1; i <= n; i++) {
        ans = max(ans, DP[i]);
    }
    cout << ans;
    return 0;
}