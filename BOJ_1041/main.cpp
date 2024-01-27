#include <iostream>
#include <algorithm>

using namespace std;

int dice[7], M;
long long sum[4], ans[4];
long long tmp, n;

void solve() {
    if (n == 1) {
        cout << tmp - M;
        return;
    }
    ans[0] = min(dice[0], dice[5]);
    ans[1] = min(dice[1], dice[4]);
    ans[2] = min(dice[2], dice[3]);
    sort(ans, ans + 3);
    ans[1] += ans[0]; //두 면 최솟값
    ans[2] += ans[1]; //세 면 최솟값
    sum[3] = 4 * ans[2]; //세 면 나오는 애들 합
    sum[2] = (4 + (n - 2) * 8) * ans[1]; //두 면 나오는 애들 합
    sum[1] = ((n - 2) * (n - 2) + 4 * (n - 2) * (n - 1)) * ans[0]; //한 면 나오는 애들 합
    cout << sum[1] + sum[2] + sum[3];
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < 6; i++) {
        cin >> dice[i];
        tmp += dice[i];
        M = max(dice[i], M);
    }
    solve();
}