#include <iostream>
#include <queue>

using namespace std;

int n, m, sum;
priority_queue<int> pq_neg;
priority_queue<int> pq_pos;

void solve() {
    int cnt = 0;
    int distance = 0;

    while (!pq_neg.empty()) {
        int tmp = pq_neg.top();
        pq_neg.pop();
        cnt++;
        if (cnt == 1) {
            distance = tmp;
        } else if (cnt == m) {
            cnt = 0;
            sum += distance * 2;
            distance = 0; //마지막에 distance*2를 더해줄 때 하나만 남았던 거 아니면 더 더해지지 않도록
        }
    }
    sum += distance * 2;

    cnt = 0;
    distance = 0;
    while (!pq_pos.empty()) {
        int tmp = pq_pos.top();
        pq_pos.pop();
        cnt++;
        if (cnt == 1) {
            distance = tmp;
        } else if (cnt == m) {
            cnt = 0;
            sum += distance * 2;
            distance = 0; //마지막에 distance*2를 더해줄 때 하나만 남았던 거 아니면 더 더해지지 않도록
        }
    }
    sum += distance * 2;
}

int main() {
    int i, dis;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> dis;
        if (dis < 0) {
            pq_neg.push((-1) * dis);
        } else {
            pq_pos.push(dis);
        }
    }

    if (pq_neg.size() > 0 && pq_pos.size() > 0
        && pq_neg.top() > pq_pos.top()) {
        sum += pq_neg.top();
        for (i = 0; i < m; i++) {
            if (!pq_neg.empty())
                pq_neg.pop();
        }
        solve();
    } else if (pq_neg.size() > 0 && pq_pos.size() > 0
               && pq_neg.top() <= pq_pos.top()) {
        sum += pq_pos.top();
        for (i = 0; i < m; i++) {
            if (!pq_pos.empty())
                pq_pos.pop();
        }
        solve();
    } else if (pq_neg.size() == 0) {
        sum += pq_pos.top();
        for (i = 0; i < m; i++) {
            if (!pq_pos.empty())
                pq_pos.pop();
        }
        solve();
    } else if (pq_pos.size() == 0) {
        sum += pq_neg.top();
        for (i = 0; i < m; i++) {
            if (!pq_neg.empty())
                pq_neg.pop();
        }
        solve();
    }
    cout << sum;
    return 0;
}