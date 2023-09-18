#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, size_pos, size_neg, idx_pos, idx_neg;
int dis_neg, dis_pos, ans;
vector<int> pos;
vector<int> neg;

void solve() {
    int i, M = 0;
    for (i = idx_pos; i >= 0; i -= m) {
        dis_pos += pos[i] * 2;
    }
    for (i = idx_neg; i >= 0; i -= m) {
        dis_neg += neg[i] * 2;
    }
    if (size_pos != 0 && size_neg != 0)
        M = max(pos[idx_pos], neg[idx_neg]);
    else if (size_pos == 0) {
        M = neg[idx_neg];
    } else if (size_neg == 0) {
        M = pos[idx_pos];
    }
    ans = dis_pos + dis_neg - M;
}

int main() {
    int i;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        int dis;
        cin >> dis;
        if (dis < 0) {
            neg.push_back((-1) * dis);
        } else {
            pos.push_back(dis);
        }
    }
    size_pos = pos.size();
    size_neg = neg.size();
    idx_pos = size_pos - 1;
    idx_neg = size_neg - 1;
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    solve();
    cout << ans;
    return 0;
}