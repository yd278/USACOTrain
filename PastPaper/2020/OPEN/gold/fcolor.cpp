#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> flag;
vector<vector<int>> members;
queue<int> q;
int getFlag(int x) { return flag[x] == x ? x : flag[x] = getFlag(flag[x]); }
void merge(int x, int y) {
    x = getFlag(x);
    y = getFlag(y);
    if (members[x].size() < members[y].size()) swap(x, y);
    for (int z : members[y]) {
        flag[z] = x;
        members[x].push_back(z);
    };
    for (int t : edges[y]) edges[x].push_back(t);
    if (edges[x].size() > 1) q.push(x);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    edges.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
    flag.resize(n + 1);
    members.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        flag[i] = i;
        members[i].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (edges[i].size() > 1) q.push(i);
    }

    while (!q.empty()) {
        int h = q.front();
        q.pop();
        while(edges[h].size()>1){
            int tail = edges[h].back();
            edges[h].pop_back();
            if(getFlag(tail)!=getFlag(edges[h].back())){
                merge(tail,edges[h].back());
            }
        }
    }
    vector<int> color(n + 1);
    int colorTop = 1;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            int flag = getFlag(i);
            for (int member : members[flag]) {
                color[member] = colorTop;
            }
            colorTop++;
        }
    }
    for (int i = 1; i <= n; i++) cout << color[i] << endl;
}