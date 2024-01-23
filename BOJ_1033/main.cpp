#include <iostream>
#include <vector>

using namespace std;

int n;
long long ans[11];
long long lcm = 1;
vector<pair<int, pair<int, int>>> v[11];

long long gcd(long long a, long long b) {
    return (b != 0) ? gcd(b, a % b) : a;
}

void input() {
    int i;
    cin >> n;
    for (i = 0; i < n - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        int tmp = gcd(p, q);
        p /= tmp;
        q /= tmp;
        v[a].push_back({b, {p, q}});
        v[b].push_back({a, {q, p}});
        lcm *= (p * q) / gcd(p, q); //전체의 최소공배수 구해둠
    }
}

void dfs(int node, int before) {
    int i;
    int size = v[node].size();
    for (i = 0; i < size; i++) {
        int next = v[node][i].first;
        if (next == before)
            continue;
        ans[next] = (ans[node] * v[node][i].second.second) / v[node][i].second.first; //비율대로 갱신해줌
        dfs(next, node);
    }
}

void solve() {
    int i;
    long long totalGCD = ans[0]; //전체 최대공약수 구해줌(질량의 총 합이 최소가 되게 하기 위해)
    for (i = 1; i < n; i++) {
        if (ans[i] == 0)
            continue;
        totalGCD = gcd(ans[i], totalGCD);
    }
    for (i = 0; i < n; i++) {
        cout << ans[i] / totalGCD << ' ';
    }
}

int main() {
    input(); //양방향으로 입력받기

    ans[0] = lcm; //처음에 최소공배수를 기준으로 나머지 아이들을 비율대로 갱신해줄거임
    dfs(0, -1);

    solve();
    return 0;
}