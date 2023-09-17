#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Map;

inline void switchRow(Map &m, int r) {
    for (int &x : m[r]) x = 1 - x;
}

inline void switchCol(Map &m, int c) {
    for (auto &row : m) {
        row[c] = 1 - row[c];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("5427.in", "r", stdin);
    freopen("5427.out", "w", stdout);
#endif
    int n;
    cin >> n;
    Map m;
    m.resize(n);
    for (auto &r : m) {
        r.resize(n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'L')
                m[i][j] = 0;
            else
                m[i][j] = 1;
        }
    }

    for (int r = 0; r < n; r++) {
        if (m[r][0]) switchRow(m, r);
    }

    for (int c = 0; c < n; c++) {
        if (m[0][c]) switchCol(m, c);
    }
    int sum = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            sum += m[i][j];
        }
    }
    if (sum == (n - 1) * (n - 1)) {
        cout << "1 1" << endl;
        return 0;
    }

    if (sum == 1) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (m[i][j]) {
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }

    if (sum == n - 1) {
        for (int i = 1; i < n; i++) {
            int row = 0;
            for (int j = 1; j < n; j++) {
                row += m[i][j];
            }
            if (row == sum) {
                cout << i + 1 << " 1" << endl;
                return 0;
            }
        }
        for (int j = 1; j < n; j++) {
            int col = 0;
            for (int i = 1; i < n; i++) {
                col += m[i][j];
            }
            if (col == sum) {
                cout << "1 " << j + 1 << endl;
                return 0;
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}