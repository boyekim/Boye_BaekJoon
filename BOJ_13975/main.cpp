#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long> pq;
long long sum;

void solve() {
    while (pq.size() > 1) {
        long long first = -pq.top();
        pq.pop();
        long long second = -pq.top();
        pq.pop();
        sum += first + second;
        pq.push(-(first + second));
    }
    while (!pq.empty())
        pq.pop();
}

int main() {
    long long T, i, file, K;
    cin >> T;
    while (T--) {
        cin >> K;
        for (i = 0; i < K; i++) {
            cin >> file;
            pq.push(-file);
        }
        sum = 0;
        solve();
        cout << sum << '\n';
    }
    return 0;
}