#include <iostream>
#include <cmath>

using namespace std;

int n;
int now_tab[1001], tab[1001], diff[1001], DP[1001];

void input() {
    int i;
    for (i = 0; i < n; i++) {
        cin >> now_tab[i];
    }
    for (i = 0; i < n; i++) {
        cin >> tab[i];
        diff[i] = tab[i] - now_tab[i]; //총 더 들여써야 하거나 삭제해야하는 탭의 개수 저장
    }
}

void solve() { //DP에 저장할 것: 해당 인덱스에서 최소 탭 횟수
    int i;
    DP[0] = abs(diff[0]);
    for (i = 1; i < n; i++) {
        if (diff[i] < 0 && diff[i - 1] < 0) { //이전 값이랑 지금 값 부호 둘다 음수면
            if (abs(diff[i]) <= abs(diff[i - 1])) { //뒤에 애의 절대값이 더 클 경우
                DP[i] = DP[i - 1]; //자기는 이미 탭이 다 들여써지거나 삭제 됐을 것
            } else {//지금 값이 더 절대값이 크다면
                DP[i] = DP[i - 1] + (abs(diff[i]) - abs(diff[i - 1])); //차이만큼 더 들여쓰거나 삭제해줘야됨
            }
        } else if (diff[i] > 0 && diff[i - 1] > 0) {
            if (diff[i] <= diff[i - 1]) {
                DP[i] = DP[i - 1];
            } else {
                DP[i] = DP[i - 1] + diff[i] - diff[i - 1];
            }
        } else { //부호 다르면 그냥 이전 DP값에 자기의 diffrence 더해주기
            DP[i] = DP[i - 1] + abs(diff[i]);
        }
    }
}

int main() {
    cin >> n;
    input();
    solve();
    cout << DP[n - 1];
    return 0;
}