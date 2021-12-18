/*
ID: dyh2191
LANG: C++14
TASK: inflate
*/

#include <iostream>
using namespace std;
int f[10001];
int n, m;
int points[10000], times[10000];
int main() {
#ifndef ONLINE_JUDGE
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
#endif
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i] >> times[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = times[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - times[i]] + points[i]);
        }
    }
    int res = 0;
    for (int i = 0; i <= m; i++) {
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}