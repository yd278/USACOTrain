#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;

vector<int> r_to_l;

bool dfs(int x, vector<int> &visited) {

    for (int to : edges[x]) {
        if (visited[to]) continue;
        visited[to] = 1;
        if (!r_to_l[to] || dfs(r_to_l[to], visited)){
            r_to_l[to] = x;
            return true;
        } 
    }
    return false;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("3379.in", "r", stdin);
    freopen("3379.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    edges.resize(n + 1);
    r_to_l.resize(m + 1);
    int e;
    cin >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> visited(m + 1);
        if (dfs(i, visited)) cnt++;
    }
    cout << cnt << endl;
}