#include <bits/stdc++.h>
using namespace std;
int getFlag(vector<int> &flag, int x) {
    return flag[x] == x ? x : flag[x] = getFlag(flag, flag[x]);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("3367.in", "r", stdin);
    freopen("3367.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> flag(n + 1);
    for (int i = 1; i <= n; i++) flag[i] = i;
    int x, y, z;
    while (m--) {
        cin >> z >> x >> y;
        int fx = getFlag(flag, x);
        int fy = getFlag(flag, y);
        if (z == 1) {
            if (fx != fy) flag[fx] = fy;
        } else {
            cout << (fx == fy ? "Y\n" : "N\n");
        }
    }
    return 0;
}
