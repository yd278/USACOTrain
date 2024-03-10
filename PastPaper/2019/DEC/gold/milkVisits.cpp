#include <bits/stdc++.h>
using namespace std;
struct farm {
    int colour;
    vector<int> edges;
    vector<int> queryIds;
};
struct query {
    int a, b, c;
    bool visited = false;
    int firstMiss;
    bool ans;
};

void dfs(int x, int pr, vector<farm> &farms, vector<query> &queries,
         vector<int> &miss) {
    auto &cur = farms[x];
    int tmp = miss[cur.colour];

    for (int qId : cur.queryIds) {
        auto &qry = queries[qId];
        if (qry.visited) {
            qry.ans = qry.firstMiss != miss[qry.c];
        } else {
            qry.firstMiss = miss[qry.c];
            qry.visited = true;
        }
    }
    for (auto to : cur.edges) {
        if (to != pr) {
            miss[cur.colour] = to;
            dfs(to, x, farms, queries, miss);
        }
    }
    miss[cur.colour] = tmp;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("milkVisits.in", "r", stdin);
    freopen("milkVisits.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<farm> farms(n + 1);
    int maxColor = 0;
    for (int i = 1; i <= n; i++) {
        cin >> farms[i].colour;
        if (farms[i].colour > maxColor) maxColor = farms[i].colour;
    }
    int a, b, c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        farms[a].edges.push_back(b);
        farms[b].edges.push_back(a);
    }
    vector<query> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        queries[i] = {a, b, c};
        if (farms[a].colour == c || farms[b].colour == c) {
            queries[i].ans = true;
        } else {
            farms[a].queryIds.push_back(i);
            farms[b].queryIds.push_back(i);
        }
    }
    vector<int> miss(maxColor + 1);
	dfs(1,0,farms,queries,miss);
	for(int i = 0; i < m;i++){
		cout<<queries[i].ans;
	}
	cout<<"\n";
    return 0;
}
