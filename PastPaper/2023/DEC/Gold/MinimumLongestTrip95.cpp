#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int depth = 0;
    long long labelSum = 0;
    long long prevLabel = 0;
    int inDeg = 0;
};
struct edge {
    int to;
    long long label;
    bool operator<(const edge& other) const { return label > other.label; }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("MinimumLongestTrip.in", "r", stdin);
    freopen("MinimumLongestTrip.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<node> nodes(n);
    vector<vector<edge>> edges(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long l;
        cin >> a >> b >> l;
        edges[b - 1].push_back({a - 1, l});
        nodes[a - 1].inDeg++;
    }
    for (int i = 0; i < n; i++) {
        sort(edges[i].begin(), edges[i].end());
    }
    queue<int> q;
    vector<edge> firstLayer;
    for (int i = 0; i < n; i++) {
        if (nodes[i].inDeg == 0) {
            for (auto edge : edges[i]) {
                firstLayer.push_back(edge);
            }
        }
    }

    sort(firstLayer.begin(), firstLayer.end());
    for (auto edge : firstLayer) {
        int to = edge.to;
        nodes[to].inDeg--;
        if (nodes[to].inDeg == 0) {
            nodes[to].labelSum = edge.label;
            nodes[to].depth = 1;
            nodes[to].prevLabel = edge.label;
            q.push(to);
        }
    }

    while (!q.empty()) {
        auto qh = q.front();
        q.pop();
        for (auto edge : edges[qh]) {
            int to = edge.to;
            if(nodes[to].depth<nodes[qh].depth+1 || (nodes[to].depth == nodes[qh].depth+1&&nodes[to].prevLabel>=edge.label)){
                nodes[to].depth= nodes[qh].depth+1;
                nodes[to].labelSum = nodes[qh].labelSum + edge.label;
                nodes[to].prevLabel = edge.label;
            }

            nodes[to].inDeg--;
            if (nodes[to].inDeg == 0) q.push(to);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << nodes[i].depth << " " << nodes[i].labelSum << "\n";
    }
    return 0;
}
