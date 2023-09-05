#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, s, t;
vector<pair<int, int>> v;

void solve() {
    int i;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].second);
    for (i = 1; i < n; i++) {
        int tmp = v[i].first; //시작시간
        if (tmp >= pq.top()) {
            pq.pop();
            pq.push(v[i].second);
        } else {
            pq.push(v[i].second);
        }
    }
    cout << pq.size();
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s >> t;
        v.push_back(make_pair(s, t));
    }
    sort(v.begin(), v.end());
    solve();
    return 0;
}