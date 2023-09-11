#include <iostream>
#include <stack>

using namespace std;

int n, k;
stack<char> s;
stack<char> ans;
string str;

void solve() {
    int i;
    for (i = 0; i < n; i++) {
        while (!s.empty() && str[i] > s.top() && k) { //현재 넣을 수가 stack의 top 보다 클 때 pop할것.
            s.pop();
            k--;
        }
        s.push(str[i]);
    } //그래서 숫자 큰 애들을 앞에서 부터 차곡차곡 쌓는 거임
    while (k) {
        s.pop();
        k--; //아직 다 안 빼줬을 때 맨위에 애 빼주기 (제일 나중에 들어간 애들)
    }
    while (!s.empty()) {
        ans.push(s.top());
        s.pop();
    }

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}

int main() {
    cin >> n >> k;
    cin >> str;
    solve();
    return 0;
}