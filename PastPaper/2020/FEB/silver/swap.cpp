#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;

    int layer = 0;
    for (int i = 0; i < 32; i++) {
        if ((1 << i) > k) {
            layer = i;
            break;
        }
    }

    vector<vector<int>> perm(layer);
    for (auto &l : perm) {
        l.resize(n + 1);
    }
    for (int i = 1; i <= n; i++) {
        perm[0][i] = i;
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        reverse(perm[0].begin() + l, perm[0].begin() + r + 1);
    }
    for (int l = 1; l < layer; l++) {
        vector<int> tmp(perm[l - 1]);
        for (int i = 1; i <= n; i++) {
            perm[l][i] = tmp[perm[l - 1][i]];
        }
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }
    for (int l = 0; l < layer; l++) {
        if ((1 << l) & k) {
            vector<int> tmp(ans);
            for (int i = 1; i <= n; i++) {
                ans[i] = tmp[perm[l][i]];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}