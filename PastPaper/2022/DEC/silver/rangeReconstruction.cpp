#include <bits/stdc++.h>
using namespace std;
bool check(int p, vector<vector<int>> &r, vector<int> &ans) {
    int mi = ans[p];
    int ma = ans[p];
    for (int i = p - 1; i >= 0; i--) {
        if (ans[i] > ma) ma = ans[i];
        if (ans[i] < mi) mi = ans[i];
        if (ma - mi != r[i][p]) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> r(n);
    for (auto &x : r) x.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> r[i][j];
        }
    }
    vector<int> ans(n);
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] + r[i - 1][i];
        if (!check(i, r, ans)) ans[i] = ans[i - 1] - r[i - 1][i];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[n - 1] << endl;
    return 0;
}
