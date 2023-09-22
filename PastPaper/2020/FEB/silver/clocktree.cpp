#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int pr, vector<int> &dp, vector<vector<int>> &edges) {
    for (auto to : edges[x]) {
        if (to != pr) {
            dfs(to, x, dp, edges);
            int delta = 12 - dp[to];
            dp[x] += delta;
            dp[x] %= 12;
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> time(n + 1);
    vector<vector<int>> edges(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> time[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> dp(time);
        dfs(i, 0, dp, edges);
        if (dp[i] == 0 || dp[i]==1) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}