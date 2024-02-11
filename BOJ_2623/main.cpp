#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int deg[1001], arr[1001], ans[1001];
vector<int> v[1001];

void input() {
    int i, j, num;
    for (i = 0; i < m; i++) {
        cin >> num;
        for (j = 0; j < num; j++) {
            cin >> arr[j];
        }
        for (j = 0; j < num; j++) {
            if (j > 0) {
                int now = arr[j - 1];
                int next = arr[j];
                v[now].push_back(next);
                deg[next]++;
            }
        }
    }
}

void topology() {
    int i, j;
    queue<int> q;
    for (i = 1; i <= n; i++) {
        if (deg[i] == 0)
            q.push(i);
    }
    for (i = 0; i < n; i++) {
        if (q.empty()) {
            cout << 0;
            exit(0);
        }
        int now = q.front();
        q.pop();
        ans[i] = now;
        int size = v[now].size();
        for (j = 0; j < size; j++) {
            int next = v[now][j];
            deg[next]--;
            if (deg[next] == 0)
                q.push(next);
        }
    }
}

int main() {
    cin >> n >> m;
    input();
    topology();
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}