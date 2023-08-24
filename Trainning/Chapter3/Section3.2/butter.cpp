/*
ID: dyh2191
LANG: C++14
TASK: butter
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct edge {
    int to, len;
};

struct node {
    int id, dist;
    vector<edge> edges;
    bool operator<(const node &other) const { return dist > other.dist; }
} nodes[801];

int done[801];
int cows[501];
int n, p, c;
int dijkstra(int source) {
    priority_queue<node> q;
    for (int i = 1; i <= p; i++) {
        done[i] = 0;
        nodes[i].dist = INT_MAX;
    }

    nodes[source].dist = 0;
    q.push(nodes[source]);

    while (!q.empty()) {
        node qh = q.top();
        q.pop();
        int index = qh.id;
        if (!done[index]) {
            done[index] = 1;
            for (auto e : qh.edges) {
                int to = e.to;
                int len = e.len;

                if (nodes[to].dist > qh.dist + len) {
                    nodes[to].dist = qh.dist + len;
                    q.push(nodes[to]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += nodes[cows[i]].dist;
    }
    return ans;
}

int main() {
    node A;
    node B;
    A < B;
    A.operator<(B);
#ifndef ONLINE_JUDGE
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
#endif
    cin >> n >> p >> c;
    for (int i = 0; i < n; i++) cin >> cows[i];
    for (int i = 1; i <= p; i++) nodes[i].id = i;
    for (int i = 0; i < c; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        nodes[a].edges.push_back(edge{b, l});
        nodes[b].edges.push_back(edge{a, l});
    }
    int min = INT_MAX;
    for (int i = 1; i <= p; i++) {
        int tmp = dijkstra(i);
        if (min > tmp) min = tmp;
    }
    cout << min << endl;
}