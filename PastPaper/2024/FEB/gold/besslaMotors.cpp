#include <bits/stdc++.h>

#include <queue>
#include <unordered_set>

using namespace std;
struct edge {
    int to, len;
};
struct vertex {
    int d, index, charger;
    bool operator<(const vertex &other) const {
        if (d > other.d) return true;
        if (d == other.d && index > other.index) return true;
        ;
        if (d == other.d && index == other.index && charger > other.charger)
            return true;
        return false;
    }
};
int main() {


    int n, m, c, r, k;
    cin >> n >> m >> c >> r >> k;
    vector<vector<edge>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    int ans = 0;
    vector<unordered_set<int>> minFound(c + 1);
    vector<int> count(n + 1);
    priority_queue<vertex> q;
    for (int i = 1; i <= c; i++) {
        q.push({0, i, i});
    }
    while (!q.empty()) {
        auto qh = q.top();
        q.pop();
        int d = qh.d;
        int index = qh.index;
        int charger = qh.charger;
        if (count[index] == k) continue;
        if (minFound[charger].find(index) != minFound[charger].end()) continue;
        count[index]++;
        if (count[index] == k && index > c) ans++;
        minFound[charger].insert(index);
        for (auto e : edges[index]) {
            if (count[e.to] < k && e.len + d <= r) {
                q.push({e.len + d, e.to, charger});
            }
        }
    }
    cout << ans << "\n";
    for (int i = c + 1; i <= n; i++) {
        if (count[i] == k) {
            cout << i << "\n";
        }
    }

    return 0;
}
