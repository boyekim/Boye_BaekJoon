#include <iostream>
#include <algorithm>

using namespace std;

int n, h;
long long ob_s[500002], ob_j[500002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long ans = 1e13 + 7;
    int i;

    cin >> n >> h;

    for (i = 0; i < n / 2; i++) {
        int ob_even, ob_odd;
        cin >> ob_even >> ob_odd;
        ob_s[ob_even]++;
        ob_j[h - ob_odd + 1]++;
    }

    for (i = h + 1; i > 1; i--) {
        ob_s[i - 1] += ob_s[i];
    }

    for (i = 1; i <= h; i++) {
        ob_j[i] += ob_j[i - 1];
    }
    int cnt = 1;
    for (i = 1; i <= h; i++) {
        if (ans > ob_s[i] + ob_j[i]) {
            ans = ob_s[i] + ob_j[i];
            cnt = 1;
        } else if (ans == ob_s[i] + ob_j[i])
            cnt++;
    }

    cout << ans << ' ' << cnt;
    return 0;
}