#include <iostream>
#include <algorithm>

#define MAX 10001

using namespace std;

int n, m;
long long minute[MAX];
long long maxMinute;

long long binary() {
    int i;
    long long start = 0, end = n * maxMinute;
    while (start <= end) {
        long long mid = (start + end) / 2; //사람 몇명 타는지 찾는 분
        long long sum = 0;
        for (i = 1; i <= m; i++) {
            long long tmp = mid / minute[i];
            if (mid % minute[i] != 0)
                tmp++;
            sum += tmp;
        }
        if (sum < n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}

int main() {
    int i;
    long long before = 0;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> minute[i];
        maxMinute = max(maxMinute, minute[i]);
    }

    long long ans = binary();
    for (i = 1; i <= m; i++) {
        long long tmp = (ans - 1) / minute[i];
        if ((ans - 1) % minute[i] != 0)
            tmp++;
        before += tmp;
    }

    for (i = 1; i <= m; i++) {
        if ((ans - 1) % minute[i] == 0) {
            before++;
        }
        if (before == n) {
            cout << i;
            break;
        }
    }
    return 0;
}