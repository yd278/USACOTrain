#include <bits/stdc++.h>
using namespace std;
bool check(int i, int j, vector<vector<char>>& field) {
    if (i < 0) return false;
    if (i >= field.size()) return false;
    if (j < 0) return false;
    if (j >= field[0].size()) return false;
    return field[i][j] == '*';
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("2670.in", "r", stdin);
    freopen("2670.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> field(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> field[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '?') {
                int sum = 0;
                for (int r = i - 1; r <= i + 1; r++) {
                    for (int c = j - 1; c <= j + 1; c++) {
                        if (check(r, c, field)) sum++;
                    }
                }
                field[i][j] = sum + '0';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }

    return 0;
}
