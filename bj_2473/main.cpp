#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;
int n;
long long ans = 5e9;
int result[3];

void binary() {
    int i;
    long long tmp;
    for (i = 0; i < n; i++) {
        long long sum = v[i];
        int start = i + 1;
        int end = n - 1;
        while (start < end) {
            tmp = v[start] + v[end];
            if (abs(tmp + sum) < abs(ans)) {
                ans = tmp + sum;
                result[0] = v[i];
                result[1] = v[start];
                result[2] = v[end];
            }
            if (tmp + sum < 0)
                start++;
            else if (tmp + sum > 0)
                end--;
            else
                return;
        }
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
    for (i = 0; i < 3; i++)
        cout << result[i] << ' ';
    return 0;
}