#include <iostream>
#include <algorithm>

#define MAX 1002

using namespace std;

int n;
int t[MAX], P[MAX], DP[MAX];

void input() {
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> t[i] >> P[i];
}

void solve() {
    int i;
    for (i = n; i > 0; i--) {
        int tmp = i + t[i];
        if (tmp > n + 1) {
            DP[i] = DP[i + 1];
            continue;
        }
        DP[i] = max(DP[i + 1], DP[tmp] + P[i]);
    }
}

int main() {
    input();
    solve();
    cout << DP[1];
    return 0;
}