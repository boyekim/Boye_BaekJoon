#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int n, k, idx, result;
int num[8];

void input(int number) {
    idx = 0;
    while (number) {
        num[idx++] = number % 10;
        number /= 10;
    }
    reverse(num, num + idx);
    if (idx == 1 || (idx == 2 && num[1] == 0)) {
        cout << -1;
        exit(0);
    }
}

int makeToInt() {
    int i, ans = 0;
    for (i = 0; i < idx; i++) {
        ans = (ans * 10) + num[i];
    }
    return ans;
}

void bfs() {
    int i, j, K;
    queue<int> q;
    q.push(n);
    while (k--) {
        if (q.empty()) {
            cout << -1;
            exit(0);
        }
        set<int> visited;
        int size = q.size();
        for (K = 0; K < size; K++) {
            int now = q.front();
            q.pop();
            input(now);
            for (i = 0; i < idx - 1; i++) {
                for (j = i + 1; j < idx; j++) {
                    if (i == 0 && num[j] == 0)
                        continue;
                    swap(num[i], num[j]);
                    int tmp = makeToInt();
                    if (visited.find(tmp) == visited.end()) {
                        visited.insert(tmp);
                        q.push(tmp);
                    }
                    if (k == 0)
                        result = max(result, tmp);
                    swap(num[i], num[j]);
                }
            }
        }
    }
}

int main() {
    cin >> n >> k;
    bfs();
    cout << result;
    return 0;
}