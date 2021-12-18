/*
ID: dyh2191
LANG: C++14
TASK: shopping
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct plan {
    int k[5];
    int p;
} plans[110];

int s;
int b;
vector<int> lines[99];
struct item {
    int c, k, p;
    bool operator<(const item &other) const { return c < other.c; }
} items[5];

int dp[6][6][6][6][6];
void input() {
    cin >> s;
    int n;
    int x, y;
    for (int i = 0; i < s; i++) {
        cin >> n;
        lines[i].push_back(n);
        for (int j = 0; j < n; j++) {
            cin >> x >> y;
            lines[i].push_back(x);
            lines[i].push_back(y);
        }
        cin >> x;
        lines[i].push_back(x);
    }
    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> items[i].c >> items[i].k >> items[i].p;
    }

    sort(items, items + b);

    for (int i = 0; i < s; i++) {
        auto plan_line = lines[i];
        int n = plan_line[0];
        for (int kk = 0; kk < n; kk++) {
            int c = plan_line[kk * 2 + 1];
            int k = plan_line[kk * 2 + 2];
            for (int j = 0; j < b; j++) {
                if (items[j].c == c) {
                    plans[i].k[j] = k;
                }
            }
        }
        plans[i].p = plan_line.back();
    }
    for (int i = 0; i < b; i++) {
        plans[s + i].k[i] = 1;
        plans[s + i].p = items[i].p;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
#endif
    input();
    for (int i0 = 0; i0 < 6; i0++)
        for (int i1 = 0; i1 < 6; i1++)
            for (int i2 = 0; i2 < 6; i2++)
                for (int i3 = 0; i3 < 6; i3++)
                    for (int i4 = 0; i4 < 6; i4++)
                        dp[i0][i1][i2][i3][i4] = 99999999;

    dp[0][0][0][0][0] = 0;

    for (int i = 0; i < s + b; i++)
        for (int i0 = plans[i].k[0]; i0 <= items[0].k; i0++)
            for (int i1 = plans[i].k[1]; i1 <= items[1].k; i1++)
                for (int i2 = plans[i].k[2]; i2 <= items[2].k; i2++)
                    for (int i3 = plans[i].k[3]; i3 <= items[3].k; i3++)
                        for (int i4 = plans[i].k[4]; i4 <= items[4].k; i4++)
                            dp[i0][i1][i2][i3][i4] =
                                min(dp[i0][i1][i2][i3][i4],
                                    dp[i0 - plans[i].k[0]][i1 - plans[i].k[1]]
                                      [i2 - plans[i].k[2]][i3 - plans[i].k[3]]
                                      [i4 - plans[i].k[4]] +
                                        plans[i].p);

    cout << dp[items[0].k][items[1].k][items[2].k][items[3].k][items[4].k]
         << endl;
    ;
    return 0;
}
