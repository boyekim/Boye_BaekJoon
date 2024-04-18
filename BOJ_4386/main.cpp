#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
double ans;
int parent[100];
vector<pair<double, double>> v;
vector<pair<double, pair<int, int>>> map;

void init() {
    int i;
    for (i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

void cal() {
    double x1, x2, y1, y2;
    for (int i = 0; i < n; i++) {
        x1 = v[i].first;
        y1 = v[i].second;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            x2 = v[j].first;
            y2 = v[j].second;
            double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            map.push_back({distance, {i, j}});
        }
    }
    sort(map.begin(), map.end());
}

int findRoot(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = findRoot(parent[a]);
}

void Union(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    parent[a] = b;
}

void kruskal() {
    int size = map.size();
    for (int i = 0; i < size; i++) {
        int node1, node2;
        node1 = findRoot(map[i].second.first);
        node2 = findRoot(map[i].second.second);
        if (node1 == node2)
            continue;
        Union(node1, node2);
        ans += map[i].first;
    }
}

int main() {
    float x, y;
    cin >> n;
    init();

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    cal();
    kruskal();
    printf("%.2f", ans);
    return 0;
}