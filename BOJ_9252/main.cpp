#include <iostream>
#include <algorithm>

using namespace std;

string str1, str2;
int len1, len2, row, col;
int DP[1001][1001];
string ans;

void solve() {
    int i, j;
    for (i = 1; i < len2; i++) {
        for (j = 1; j < len1; j++) {
            if (str1[j] == str2[i]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
        }
    }

}

void findStr() {
    row = len2 - 1;
    col = len1 - 1;
    while (DP[row][col]) {
        if (DP[row][col] == DP[row - 1][col])
            row--;
        else if (DP[row][col] == DP[row][col - 1])
            col--;
        else {
            ans += str2[row];
            row--;
            col--;;
        }
    }
}

int main() {
    string tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    str1 = '0' + tmp1;
    str2 = '0' + tmp2;
    len1 = str1.length();
    len2 = str2.length();
    solve();
    findStr();
    cout << DP[len2 - 1][len1 - 1] << '\n';
    if (ans.length() != 0) {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}