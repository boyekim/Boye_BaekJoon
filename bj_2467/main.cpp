#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int ans[2];
vector<int> v;

void binary() {
    int start = 0, end = n - 1;
    int sum = 2e9;
    while (start < end) {
        int tmp = v[start] + v[end];
        if (abs(tmp) < abs(sum)) {
            sum = tmp;
            ans[0] = v[start];
            ans[1] = v[end];
        }
        if (tmp < 0) {
            start++;
        } else if (tmp > 0) {
            end--;
        } else
            return;
    }
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        int f;
        cin >> f;
        v.push_back(f);
    }
    sort(v.begin(), v.end());
    binary();
    cout << ans[0] << ' ' << ans[1];
    return 0;
}