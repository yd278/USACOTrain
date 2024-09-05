#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 10005
#define MAXM 500005
struct Edge {
    int to, len;
};
vector<Edge> edges[MAXN];
int dist[MAXN];
int isIn[MAXN];
queue<int> q;
int main() {
#ifndef ONLINE_JUDGE
    freopen("3371.in", "r", stdin);
    freopen("3371.out", "w", stdout);
#endif
    int n, m, s;
    cin >> n >> m >> s;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Edge tmp = {b, c};
        edges[a].push_back(tmp);
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = 2147483647;
    }
    dist[s] = 0;
    q.push(s);
    isIn[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        isIn[u] = 0;
        for (auto edge : edges[u]) {
            int to = edge.to;
            int len = edge.len;
            if (dist[to] > dist[u] + len) {
                dist[to] = dist[u] + len;
                if (!isIn[to]) {
                    q.push(to);
                    isIn[to] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}