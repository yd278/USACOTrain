#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000
#define MAXM 500000

struct Query {
    int index, other;
};

vector<int> edges[MAXN + 10];

vector<Query> querys[MAXN + 10];

int ans[MAXM + 10];

// 0:haven't been in the stack; 1: in the stack; 2:has popped out;
int state[MAXN + 10];

int flag[MAXN + 10];
int getFlag(int x) { return x == flag[x] ? x : flag[x] = getFlag(flag[x]); }

void dfs(int now, int pa) {       // now：正在搜的点， pa：parent节点
    state[now] = 1;               // 正在搜，所以把状态改成1
    for (auto q : querys[now]) {  // 对于所有挂在这个节点上的询问
        if (state[q.other] == 1) {  // 如果另一个点的状态也是1
            ans[q.index] = q.other;  // 那么它们的最近公共祖先就是另一个点
        } else if (state[q.other] == 2) {  // 如果另一个点的状态是2
            ans[q.index] = getFlag(
                q.other);  // 那么它们的最近公共祖先就是另一个点所在的并查集的flag
        }
    }
    for (auto to : edges[now]) {  // 对于所有从这个点连出去的边
        if (to != pa) {           // 除了是parent节点的那条边
            dfs(to, now);         // 搜相对应的节点
        }
    }
    state[now] = 2;  // 搜完了，把状态改成2
    flag[now] = getFlag(pa);  // 并且把自己这个点在并查集上连到parent上去
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
#endif
    int n, m, s;
    cin >> n >> m >> s;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        flag[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        Query tmp1 = {i, a};
        querys[b].push_back(tmp1);
        Query tmp2 = {i, b};
        querys[a].push_back(tmp2);
    }

    dfs(s, 0);
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
