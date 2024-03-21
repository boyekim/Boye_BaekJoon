#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k, mini_sq, maxi_sq;
vector<pair<int, int>> v; //1,2,3,4 , 길이

void input() {
    int i, len, direction;
    for (i = 0; i < 6; i++) {
        cin >> direction >> len;
        v.push_back({direction, len});
        if (direction == 3 || direction == 4) {
            c = max(len, c);
        } else {
            r = max(len, r);
        }
    }
    for (i = 0; i < 6; i++) {
        v.push_back({v[i].first, v[i].second});
    }
    maxi_sq = c * r;
}

void solve() {
    int i;
    for (i = 0; i < 6; i++) {
        if (v[i].first == v[i + 2].first && v[i + 1].first == v[i + 3].first) {
            mini_sq = v[i + 1].second * v[i + 2].second;
            break;
        }
    }
    cout << (maxi_sq - mini_sq) * k;
}

int main() {
    cin >> k;
    input();
    solve();
    return 0;
}