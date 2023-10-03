#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int n, check;
string str;
bool Reverse = false;

void Function() {
    int i;
    for (i = 0; i < str.length(); i++) {
        if (str[i] == 'R') {
            if (Reverse)
                Reverse = false;
            else
                Reverse = true;
        } else {
            if (dq.empty()) {
                cout << "error" << '\n';
                check = 0;
                return;
            }
            if (Reverse)
                dq.pop_back();
            else
                dq.pop_front();
        }
    }
}

int main() {
    int T, i;
    cin >> T;
    while (T--) {
        char c;
        int tmp;
        dq.clear();
        Reverse = false;
        check = 1;
        cin >> str;
        cin >> n;
        if (n == 0)
            cin >> c;
        cin >> c;
        for (i = 0; i < n; i++) {
            cin >> tmp;
            dq.push_back(tmp);
            cin >> c;
        }
        Function();
        if (check == 0) {
            continue;
        }
        cout << '[';
        if (dq.empty()) {
            cout << ']' << '\n';
            continue;
        }
        if (Reverse) {
            for (auto o = dq.rbegin(); o != dq.rend(); o++) {
                if (o == dq.rend() - 1)
                    cout << *o << ']' << '\n';
                else
                    cout << *o << ',';
            }
        } else {
            for (auto o = dq.begin(); o != dq.end(); o++) {
                if (o == dq.end() - 1)
                    cout << *o << ']' << '\n';
                else
                    cout << *o << ',';
            }
        }
    }
    return 0;
}