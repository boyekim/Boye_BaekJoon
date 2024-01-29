#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, longest;
int result[100];
bool check;
vector<pair<int, int>> v; //처음이 가격 두번째가 숫자

void init() {
    int i;
    if (m / v[0].first != 1 && v[0].second == 0 && v[1].first <= m) {
        check = true;
        result[0] = v[1].second;
        m -= v[1].first;
        longest = m / v[0].first;
        longest++;
    } else {
        longest = m / v[0].first;
        result[0] = v[0].second;
        m -= v[0].first;
    }
    
    for (i = 1; i < longest; i++) {
        result[i] = v[0].second;
        m -= v[0].first; //이제 m에는 남은 돈만 남는다.
    }
}

int find() {
    int i, idx = 0;
    for (i = 0; i < n; i++) {
        if (m < v[i].first) {
            m -= v[idx].first;
            return v[idx].second;
        }

        //0보다 작아지는 첫 시점의 직전 시점이 제일 큰 번호라고 할 수 없기 때문에 조건을 만족시킬때마다 최대 번호를 가지고 있는 인덱스로 갱신해줘야 함
        if (v[idx].second < v[i].second) {
            idx = i;
        }
    }
    m -= v[idx].first;
    return v[idx].second;
}

void solve() {
    int i;
    for (i = 0; i < longest; i++) {
        if (check && i == 0) {
            m += v[1].first;
            result[i] = find();
        } else {
            m += v[0].first;
            result[i] = find();
        }
    }
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        int price;
        cin >> price;
        v.push_back({price, i});
    }
    sort(v.begin(), v.end());
    cin >> m;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    init();
    solve();
    if (result[0] == 0 && result[n - 1] == 0) {
        cout << 0;
        return 0;
    }
    for (i = 0; i < longest; i++) {
        cout << result[i];
    }
    return 0;
}