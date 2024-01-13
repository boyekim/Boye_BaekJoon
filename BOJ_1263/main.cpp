#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, last = 2e9;
vector<pair<int, int>> v;

void solve() {
    int i;
    for (i = 0; i < n; i++) {
        int deadLine = v[i].first;
        int Time = v[i].second;
        if (last < deadLine) {
            deadLine = last;
        }
        last = deadLine - Time;
        if (last < 0) {
            cout << -1;
            return;
        }
    }
    cout << last;
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        int s, t;
        cin >> t >> s;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    solve();
    return 0;
}