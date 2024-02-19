#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int n, k;
string str, cmp;
map<string, bool> visited;

void input() {
    int i;
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        str += tmp;
    }
    cmp = str;
    sort(cmp.begin(), cmp.end());
}

void bfs() {
    queue<pair<string, int>> q;
    int i;
    q.push({str, 0});
    visited[str] = true;
    while (!q.empty()) {
        string now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (now == cmp) {
            cout << cnt;
            return;
        }
        for (i = 0; i < n; i++) {
            if (i + k > n)
                continue;
            string tmp = now.substr(i, k);
            reverse(tmp.begin(), tmp.end());
            string next = now.substr(0, i) + tmp + now.substr(i + k, n - k - i);
            if (visited.find(next) != visited.end())
                continue;
            visited.insert({next, true});
            q.push({next, cnt + 1});
        }
    }
    cout << -1;
}

int main() {
    input();
    bfs();
    return 0;
}