#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<string> v; //입력받은 문자열을 저장
vector<pair<long long, char>> result; //알파벳들과 나온 자릿수를 통한 숫자 계산 한 것을 저장
long long cnt[12], number[12]; //cnt는 자릿수에 따른 숫자 계산, number는 알파벳이 가지게 된 숫자 저장
bool first[12], visited[12]; //first는 첫글자로 나온적이 있는지 여부를 저장, visited는 방문여부
int kind; //알파벳 종류가 몇개 였는지

void solve() {
    int i, j;
    int size = v.size();
    for (i = 0; i < size; i++) {
        string now = v[i];
        int len = now.length();
        long long digit = 0;
        for (j = 0; j < len; j++) {
            char alphabet = now[len - j - 1];
            if (!visited[alphabet - 'A']) {
                kind++;
                visited[alphabet - 'A'] = true;
            }
            digit *= 10;
            if (digit == 0)
                digit = 1;
            cnt[alphabet - 'A'] += digit;
        }
    }
    for (i = 0; i < 10; i++) {
        if (cnt[i] != 0)
            result.push_back({cnt[i], 'A' + i});
    }
    sort(result.begin(), result.end(), greater<>());
}

void greedy() {
    int i, num = 9;
    int size = result.size();
    char now;
    if (kind == 10) { //숫자의 맨 앞이 0이 될 여지가 있다. 0을 줄 수 있는 아이한테 먼저 주기.
        for (i = size - 1; i >= 0; i--) {
            now = result[i].second;
            if (!first[now - 'A']) {
                number[now - 'A'] = 0;
                break;
            }
        }
    }
    for (i = 0; i < size; i++) {
        now = result[i].second;
        if (number[now - 'A'] == 0)
            continue;
        number[now - 'A'] = num;
        num--;
    }
}

int main() {
    int i, j;
    long long sum = 0;
    string str;
    cin >> n;
    memset(number, -1, sizeof(number));

    for (i = 0; i < n; i++) {
        cin >> str;
        first[str[0] - 'A'] = true;
        v.push_back(str);
    }

    solve();
    greedy();

    for (i = 0; i < n; i++) {
        long long ans = 0;
        str = v[i];
        int len = str.length();
        for (j = 0; j < len; j++) {
            long long num = number[v[i][j] - 'A'];
            ans = (ans * 10) + num;
        }
        sum += ans;
    }
    cout << sum;
    return 0;
}