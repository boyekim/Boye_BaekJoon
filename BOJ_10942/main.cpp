#include <iostream>

using namespace std;

int n, m;
int num[2001], DP[2001][2001];

void init() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j)
                DP[i][j] = 1;
            else
                DP[i][j] = -1;
        }
    }
}

int Pal(int start, int end) {
    int mid = (start + end) / 2;
    int now1 = start, now2 = end;

    while (now1 != mid) {
        if (num[now1] != num[now2]) {
            return DP[start][end] = 0;
        }
        if (DP[now1][now2] >= 0) {
            return DP[start][end] = DP[now1][now2];
        }
        now1++;
        now2--;
    }
    if (num[now1] != num[now2]) {
        return DP[start][end] = 0;
    }
    if (DP[now1][now2] >= 0) {
        return DP[start][end] = DP[now1][now2];
    }

    DP[start][end] = 1;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, start, end;
    cin >> n;
    init();
    for (i = 1; i <= n; i++) {
        cin >> num[i];
    }
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> start >> end;
        cout << Pal(start, end) << '\n';
    }
    return 0;
}