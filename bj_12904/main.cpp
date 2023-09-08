#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int len, i;
    string s, t; //s의 길이 < t의 길이
    cin >> s >> t;
    len = t.length() - s.length();
    for (i = 0; i < len; i++) {
        if (t.back() == 'A') {
            t.pop_back();
        } else if (t.back() == 'B') {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if (s == t)
        cout << 1;
    else
        cout << 0;
    return 0;
}