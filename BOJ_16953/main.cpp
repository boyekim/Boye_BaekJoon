#include <iostream>

using namespace std;

int A, B, cnt;

//B가 짝수면 /=2 해주고, 홀수이고 일의자리가 1이면 /=10을 해준다. A보다 작아지거나 홀수인데 일의자리가 1이아니면 A로 될 수 없음. 따라서 -1 출력후 종료

void solve() {
    while (A <= B) {
        if (A == B) {
            cout << cnt + 1;
            return;
        }
        if (B % 2 == 1) {
            if (B % 10 != 1) {
                cout << -1;
                return;
            }
            B /= 10;
        } else {
            B /= 2;
        }
        cnt++;
    }
    cout << -1;
}

int main() {
    cin >> A >> B;
    solve();
}