#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> flag;
vector<int> depth;
vector<vector<int>> pr;

void dfs(int cur, int d) {
    depth[cur] = d;
    for (int to : edges[cur]) {
        if (to != pr[0][cur]) {
            pr[0][to] = cur;
            dfs(to, d + 1);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("graphAlgos.in", "r", stdin);
    freopen("graphAlgos.out", "w", stdout);
#endif
    int n, m, s, q;
    cin >> n >> m >> s >> q;
    edges.resize(n + 1);

    int log = 0;
    for (; 1 << log <= n; log++)
        ;

    pr.resize(log);
    for (auto &row : pr) row.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // pre-process
    pr[0][s] = s;

    dfs(s, 0);

    for (int i = 1; i < log; i++) {
        for (int j = 1; j <= n; j++) {
            pr[i][j] = pr[i - 1][pr[i - 1][j]];
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (depth[a] < depth[b]) swap(a, b);

        int delta = depth[a] - depth[b];
        for (int p = 0; 1 << p <= delta; p++) {
            if ((1 << p) & delta) {
                a = pr[p][a];
            }
        }

        if (a == b) {
            cout << b << endl;
            continue;
        }
		for(int p = log-1; p >=0; p--){
			if(pr[p][a]!=pr[p][b]){
				a = pr[p][a];
				b = pr[p][b];
			}
		}
		cout<<pr[0][a]<<endl;
    }

    return 0;
}
