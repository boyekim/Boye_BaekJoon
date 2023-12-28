#include <iostream>
#include <algorithm>

using namespace std;

int DP[1000001];

int main() {
    int n, i, child, ans = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> child;
        DP[child] = DP[child - 1] + 1;
        ans = max(DP[child], ans);
    }
    cout << n - ans;
}