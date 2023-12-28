#include <iostream>

#define MAX 100001

using namespace std;

int utilityPole[MAX];
int LIS[MAX];
int idx, n;

int binary(int end, int cmp) {
    int start = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (LIS[mid] > cmp) {
            end = mid - 1;
        } else
            start = mid + 1;
    }
    return start;
}

void solve() {
    int i;
    LIS[0] = utilityPole[0];
    for (i = 0; i < n; i++) {
        if (LIS[idx] < utilityPole[i]) {
            LIS[++idx] = utilityPole[i];
        } else {
            int tmp = binary(idx, utilityPole[i]);
            LIS[tmp] = utilityPole[i];
        }
    }
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> utilityPole[i];
    }
    solve();
    idx++;
    cout << n - idx;
    return 0;
}