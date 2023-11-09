#include <iostream>

#define INF 2e9

using namespace std;

int n, k;//n은 학생수, k는 가지고있는 돈
int parent[10001], request_money[10001];
int minimum_money[10001];

void init() {
    int i;
    for (i = 1; i <= n; i++) {
        parent[i] = i;
        minimum_money[i] = INF;
    }
}

int findParent(int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void Union(int nodeA, int nodeB) {
    nodeA = findParent(nodeA);
    nodeB = findParent(nodeB);
    if (nodeA < nodeB) {
        parent[nodeB] = nodeA;
    } else
        parent[nodeA] = nodeB;
}

int main() {
    int m, i, money = 0; //m은 친구관계 수
    cin >> n >> m >> k;
    init();

    for (i = 1; i <= n; i++) {
        cin >> request_money[i];
    }

    for (i = 0; i < m; i++) {
        int friendA, friendB;
        cin >> friendA >> friendB;
        Union(friendA, friendB);
    }

    for (i = 1; i <= n; i++) {
        int tmp = findParent(i);
        minimum_money[tmp] = min(minimum_money[tmp], request_money[i]);
    }

    for (i = 1; i <= n; i++) {
        if (minimum_money[i] == INF)
            continue;
        money += minimum_money[i];
    }
    if (money > k) {
        cout << "Oh no";
    } else
        cout << money;
    return 0;
}