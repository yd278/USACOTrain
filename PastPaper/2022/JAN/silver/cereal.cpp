#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int cow;
    int to;
};
vector<vector<Edge>> graph;
vector<bool> visited_cycle;
vector<bool> visited;
vector<bool> not_hungry;
vector<int> order;
vector<int> first;
int cycleCow;
bool findCycle(int v, int pr) {
    visited_cycle[v] = 1;
    for (auto e : graph[v]) {
        if (e.to == pr) continue;
        if (visited_cycle[e.to]) {
            cycleCow = e.cow;
            return true;
        }
        if (findCycle(e.to, v)) return true;
    }
    return false;
}
void dfs(int v) {
    visited[v] = 1;
    for (auto e : graph[v]) {
        if (visited[e.to]) continue;
        if (e.cow == cycleCow) continue;
        order.push_back(e.cow);
        dfs(e.to);
    }
}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("cereal.in", "r", stdin);
//     freopen("cereal.out", "w", stdout);
// #endif
    int n, m;
    cin >> n >> m;
    graph.resize(m + 1);
    visited_cycle.resize(m + 1);
    visited.resize(m + 1);
    not_hungry.resize(n + 1);
    first.resize(n + 1);
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        graph[a].push_back({i, b});
        graph[b].push_back({i, a});
        first[i] = a;
    }

    for (int i = 1; i <= m; i++) {
        if (!visited[i]) {
            if (findCycle(i, 0)) {
                order.push_back(cycleCow);
                dfs(first[cycleCow]);
            } else {
                dfs(i);
            }
        }
    }

    cout << n - order.size() << endl;
    for (auto c : order) {
        cout << c << endl;
        not_hungry[c] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!not_hungry[i]) cout << i << endl;
    }
    return 0;
}