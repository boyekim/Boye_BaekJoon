#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<int> pre, in;

void input() {
    pre.clear();
    in.clear();
    int i, node;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> node;
        pre.push_back(node);
    }
    for (i = 0; i < n; i++) {
        cin >> node;
        in.push_back(node);
    }
}

void solve(int start, int end, int idx) {
    int i;
    for (i = start; i < end; i++) {
        if (in[i] == pre[idx]) {
            solve(start, i, idx + 1);
            solve(i + 1, end, idx + 1 + i - start);
            cout << pre[idx] << ' ';
        }
    }
}

int main() {
    int i;
    cin >> t;
    while (t--) {
        input();
        solve(0, n, 0);
        cout << '\n';
    }
    return 0;
}