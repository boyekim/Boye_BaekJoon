#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[501];
int DP[501], needSec[501]; //DP는 그 건물 지을 때 필요한 최소 시간

void solve(int building) {
    int i;
    for (i = 0; i < v[building].size(); i++) {
        int tmp = v[building][i];
        if (DP[tmp] != -1) {
            DP[building] = max(DP[building], DP[tmp] + needSec[building]);
        } else {
            solve(tmp);
            DP[building] = max(DP[building], DP[tmp] + needSec[building]);
        }
    }
}

int main() {
    int i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        int input = 0, sec;
        cin >> sec;
        needSec[i] = sec;
        while (1) {
            cin >> input;
            if (input == -1)
                break;
            v[i].push_back(input);
        }
        if (v[i].size() == 0) //다른 건물 우선 안지어도 되면 DP에 미리 저장해둠
            DP[i] = needSec[i];
        else //다른 건물 필요하면 -1 저장
            DP[i] = -1;
    }

    for (i = 1; i <= n; i++) {
        if (DP[i] == -1)
            solve(i);
    }
    for (i = 1; i <= n; i++) {
        cout << DP[i] << '\n';
    }
    return 0;
}