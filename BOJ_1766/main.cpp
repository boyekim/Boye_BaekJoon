#include <iostream>
#include <vector>
#include <queue>

#define MAX 32001

using namespace std;

int n, m;
int deg[MAX], result[MAX];
vector<int> v[MAX];

void input() {
    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        deg[b]++;
        v[a].push_back(b);
    }
}

void topologySort() {
    int i, j;
    priority_queue<int> q;

    for (i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(-i);
        }
    }

    for (i = 0; i < n; i++) {
        if (q.empty()) {
            return;
        }
        int now = -q.top();
        int size = v[now].size();
        q.pop();
        result[i] = now;
        for (j = 0; j < size; j++) {
            int next = v[now][j];
            deg[next]--;
            if (deg[next] == 0) {
                q.push(-next);
            }
        }
    }
}

int main() {
    input();
    topologySort();
    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}