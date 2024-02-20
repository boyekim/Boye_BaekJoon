#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str1, str2;
int len1, len2, ans;
int DP[4001][4001];

int main() {
    int i, j;
    string tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    str1 = " " + tmp1;
    str2 = " " + tmp2;
    len1 = str1.length();
    len2 = str2.length();
    for (i = 1; i < len1; i++) {
        for (j = 1; j < len2; j++) {
            if (str1[i] == str2[j]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                ans = max(ans, DP[i][j]);
            } else {
                DP[i][j] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}