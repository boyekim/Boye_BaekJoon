#include <iostream>
#include <algorithm>

using namespace std;

string str1, str2;
int DP[1001][1001];

int main() {
    int i, j;
    cin >> str1 >> str2;
    int len1 = str1.length();
    int len2 = str2.length();
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
            }
        }
    }

    cout << DP[len1][len2];
    return 0;
}