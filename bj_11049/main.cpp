#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[501][2];
int DP[501][501];

//항상 순서대로 곱셈을 할 수 있는 크기만 입력으로 주어진다.
int main() {
    int i, k, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            DP[j][j + i] = 2e9;
            for (k = j; k <= i + j; k++) {
                DP[j][j + i] = min(DP[j][j + i], DP[j][k] + DP[k + 1][i + j] +
                                                 arr[j][0] * arr[k][1] * arr[j + i][1]);
            }
        }
    }
    cout << DP[1][n];
    return 0;
}