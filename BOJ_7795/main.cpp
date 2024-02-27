#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Test, n, m;//n이 a의 개수 m이 b의 개수
vector<int> a;
vector<int> b;

void input() {
    int i, tmp;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }

    for (i = 0; i < m; i++) {
        cin >> tmp;
        b.push_back(tmp);
    }
}

void solve() {
    int idx, i, j, cnt = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (i = 0; i < m; i++) {
        idx = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        cnt += n - idx;
    }
    cout << cnt << '\n';
}

int main() {
    cin >> Test;
    while (Test--) {
        a.clear();
        b.clear();
        input();
        solve();
    }
    return 0;
}