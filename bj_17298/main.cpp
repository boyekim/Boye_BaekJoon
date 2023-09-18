#include <iostream>
#include <stack>

using namespace std;

int num[1000001], ans[1000001];
int n;
stack<int> s;

void NGE() {
    int i;
    ans[n - 1] = -1;
    s.push(num[n - 1]);
    for (i = n - 2; i >= 0; i--) {
        while (!s.empty() && s.top() <= num[i]) {
            s.pop();
        }
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(num[i]);
    }
}

int main() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> num[i];
    }
    NGE();
    for (i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}