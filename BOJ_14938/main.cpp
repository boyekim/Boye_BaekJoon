#include <iostream>

#define INF 2e9

using namespace std;

int n, m, r, ans;
int item[101];
long long dist[101][101]; //거리정보 저장

void init() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
}

//각 지점에서 특정 지점까지 최단거리 싹 저장
void floyd() {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void input() {
    int i;
    for (i = 1; i <= n; i++) {
        cin >> item[i]; //지역 당 아이템 숫자
    }
    for (i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l; //거리정보 저장
        dist[a][b] = l;
        dist[b][a] = l;
    }
}

void solve() {
    int i, j;
    for (i = 1; i <= n; i++) {
        int result = item[i];
        for (j = 1; j <= n; j++) {
            if (i != j && dist[i][j] <= m) { //i에서(처음에 떨어진 지점) j까지 갈 때 수색거리 제한안에 갈 수 있다면
                result += item[j]; //해당 지역 아이템을 수거
            }
        }
        ans = max(ans, result);
    }
    cout << ans;
}

int main() {
    cin >> n >> m >> r;
    init();
    input();
    floyd(); //최단거리 저장
    solve();
    return 0;
}