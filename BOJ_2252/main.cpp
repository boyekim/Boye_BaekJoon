#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int deg[32001], result[32001];
vector<int> v[32001];

void topology() {
    int i, j;
    queue<int> q;
    for (i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i); //진입차수가 0인 아이들 q에 삽입
        }
    }
    for (i = 1; i <= n; i++) {
        if (q.empty()) {
            return;
        }
        int now = q.front();
        int size = v[now].size();
        result[i] = now;
        q.pop();
        for (j = 0; j < size; j++) {
            int next = v[now][j];
            deg[next]--;
            if (deg[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main() {
    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        deg[b]++;
    }
    topology();
    for (i = 1; i <= n; i++)
        cout << result[i] << ' ';
    return 0;
}