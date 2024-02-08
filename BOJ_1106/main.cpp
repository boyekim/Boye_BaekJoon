#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2e9

using namespace std;

int c, n, M;
vector<pair<int, int>> v; //money,명수
long long DP[1200];
long long ans = INF;

void input() {
    int i;
    cin >> c >> n; //첫째줄에 c명, 홍보할 수 있는 도시의 개수 n개
    for (i = 0; i < n; i++) {
        int money, num;
        cin >> money >> num;
        M = max(M, num);
        v.push_back({money, num});
    }
}

void init() {
    int i;
    for (i = 1; i <= c + M; i++)
        DP[i] = INF;
}

void solve() {
    int i, j;
    for (i = 1; i <= c + M; i++) {
        for (j = 0; j < n; j++) {
            int money = v[j].first;
            int num = v[j].second;
            if (i - num < 0)
                continue;
            DP[i] = min(DP[i], DP[i - num] + money);
            if (i >= c && DP[i] > 0)
                ans = min(ans, DP[i]);
        }
    }
}

int main() {
    input();
    init();
    solve();
    cout << ans;
    return 0;
}