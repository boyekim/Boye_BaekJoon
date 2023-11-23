#include <iostream>

using namespace std;

int n, idx;
int children[201];
int ans[201];

int binary(int comp) {
    int start = 0, end = idx;
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (ans[mid] < comp) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
}

void solve() {
    int i;
    ans[0] = children[0];
    for (i = 1; i < n; i++) {
        if (ans[idx] < children[i]) {
            ans[++idx] = children[i];
        } else {
            int tmp = binary(children[i]);
            ans[tmp] = children[i];
        }
    }
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> children[i];
    }
    solve();
    cout << n - (idx + 1);
    return 0;
}