#include <bits/stdc++.h>
using namespace std;

struct TreeDP {
    vector<vector<int>> &edges;
    vector<int> &l, &t, &p;

    void countLeaf(int cur, int pr) {
        if (edges[cur].size() == 1 && edges[cur][0] == pr) {
            l[cur] = 1;
            return;
        }
        for (auto to : edges[cur]) {
            if (to != pr) {
                countLeaf(to, cur);
                l[cur] += l[to];
            }
        }
    }
    void process(int cur, int pr) { 
        if (edges[cur].size() == 1 && edges[cur][0] == pr) {
            t[cur] = min(1, p[cur]);
            return;
        }
        for (auto to : edges[cur]) {
            if (to != pr) {
                process(to, cur);
                t[cur] += t[to];
            }
        }
        t[cur]+= p[cur];
        t[cur] = min(t[cur],l[cur]);
    }
};
int main() {

    int n;
    cin >> n;
    vector<vector<int>> edges(n + 1);
    vector<int> potionList(n);
    vector<int> p(n + 1);

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> potionList[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> l(n + 1);
    vector<int> t(n + 1);
    TreeDP treeDP{edges, l, t, p};
    treeDP.countLeaf(1, 0);
    for (int i = 0; i < l[1]; i++) {
        p[potionList[i]]++;
    }
    treeDP.process(1, 0);

    cout << t[1] << endl;
    return 0;
}
