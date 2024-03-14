#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l, sum;
vector<int> v;

void binary() {
    int start = 1;
    int end = l;
    int size = v.size();
    int i, mid;
    while (start <= end) {
        sum = 0;
        mid = (start + end) / 2;
        for (i = 0; i < size - 1; i++) {
            int diff = v[i + 1] - v[i];
            if (diff % mid == 0) {
                sum += (diff / mid) - 1;
            } else {
                sum += (diff / mid);
            }
        }
        if (sum > m) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << start;
}

int main() {
    int i;
    cin >> n >> m >> l;
    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(0);
    v.push_back(l);
    sort(v.begin(), v.end());
    binary();
    return 0;
}