#include <iostream>

using namespace std;

int n, idx;
int elec[40001], ans[40001];

int binary(int comp) {
    int start = 0, end = idx;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (ans[mid] < comp) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> elec[i];
    }
    ans[0] = elec[0];
    for (i = 0; i < n; i++) {
        if (ans[idx] < elec[i]) {
            ans[++idx] = elec[i];
        } else {
            int tmp = binary(elec[i]);
            ans[tmp] = elec[i];
        }
    }
    cout << idx + 1;
    return 0;
}