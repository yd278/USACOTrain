#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, len;
};

struct node {
    int id, dist;
    bool operator<(const node &other) const { return dist > other.dist; }
} nodes[100005];

vector<edge> edges[100005];

bool isIn[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("4779.in", "r", stdin);
    freopen("4779.out", "w", stdout);
#endif
    int n, m, s;
    cin >> n >> m >> s;
    int a, b, l;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> l;
        edges[a].push_back(edge{b, l});
    }
    for (int i = 1; i <= n; i++) {
        nodes[i].dist = INT_MAX / 2;
        nodes[i].id = i;
    }
    nodes[s].dist = 0;
    priority_queue<node> q;
    q.push(nodes[s]);

    while (!q.empty()) {
        node qh = q.top();
        q.pop();
        int id = qh.id;
        if (!isIn[id]) {
            isIn[id] = 1;
            for (auto e : edges[id]) {
                int to = e.to;
                int len = e.len;
                if (nodes[to].dist > qh.dist + len) {
                    nodes[to].dist = qh.dist + len;
                    q.push(nodes[to]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << nodes[i].dist << " ";
    }
    return 0;
}