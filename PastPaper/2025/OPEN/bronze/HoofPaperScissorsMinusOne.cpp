#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("HoofPaperScissorsMinusOne.in", "r", stdin);
    freopen("HoofPaperScissorsMinusOne.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    char c;
    vector<vector<int>> win(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            cin >> c;
            if (c == 'L') win[j][i] = 1;
            if (c == 'W') win[i][j] = 1;
        }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (win[i][a] && win[i][b]) cnt++;
        }
        cout << cnt * n * 2 - cnt * cnt << endl;
    }

    return 0;
}
