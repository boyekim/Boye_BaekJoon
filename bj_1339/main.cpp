#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
int alpha[27];

bool comp(int a, int b) {
    return a > b;
}

void input(string str, int size) {
    int i;
    int pow = 1;
    for (i = size - 1; i >= 0; i--) {
        char tmp = str[i];
        alpha[tmp - 'A'] += pow;
        pow *= 10;
    }
}

void cal() {
    int number = 9;
    int i;
    for (i = 0; i < 27; i++) {
        ans += alpha[i] * number;
        number--;
        if (alpha[i] == 0)
            return;
    }
}

int main() {
    int i, size;
    cin >> n;
    for (i = 0; i < n; i++) {
        string str;
        cin >> str;
        size = str.length();
        input(str, size);
    }
    sort(alpha, alpha + 27, comp);
    cal();
    cout << ans;
    return 0;
}