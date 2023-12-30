#include <iostream>
#include <deque>

using namespace std;

deque<int> d[101];
int device[101];
int n, k, idx, cnt;
int multi[101];
bool visited[101]; //현재 꼽혀있는지아닌지

int find() {
    int i, M = 0, tmp_idx, ans;
    for (i = 0; i < n; i++) {
        int tmp = multi[i];
        if (d[tmp].size() == 0) {
            tmp_idx = i;
            ans = tmp;
            break;
        }
        if (M < d[tmp].front()) { //가장 나중에 등장할 애 갱신
            tmp_idx = i;
            M = d[tmp].front();
            ans = tmp;
        }
    }
    visited[ans] = false; //멀티탭에서 뽑아
    cnt++;
    return tmp_idx;
}

void solve() {
    int i;
    for (i = 0; i < k; i++) {
        int now = device[i];
        if (visited[now]) {
            d[now].pop_front();
            continue;
        }
        if (idx < n) {
            visited[now] = true; //꼽고
            multi[idx++] = now;
        } else {
            int tmp_idx = find();
            multi[tmp_idx] = now; //끼워줘
            visited[now] = true;
        }
        d[now].pop_front();
    }
}

int main() {
    int i;
    cin >> n >> k;
    for (i = 0; i < k; i++) {
        cin >> device[i];
        d[device[i]].push_back(i);
    }
    solve();
    cout << cnt;
}