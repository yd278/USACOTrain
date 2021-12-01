#include <iostream>
using namespace std;

int f[5001][5001];
int len;
int cal(int n) {
    for (int i = 0; i <= len; i++) {
        f[n][i] = f[n - 1][i] + f[n - 2][i];
    }
    for (int i = 0; i <= len; i++) {
        if (f[n][i] >= 10) {
            f[n][i + 1] += f[n][i] / 10;
            f[n][i] %= 10;
            if (f[n][len + 1]) len++;
        }
    }
}
int main() {
    f[0][0] = 0;
    f[1][0] = 1;
    f[2][0] = 2;
#ifndef ONLINE_JUDGE
    freopen("1255.in", "r", stdin);
    freopen("1255.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        cal(i);
    }
    for (int i = len; i >= 0; i--) {
        cout << f[n][i];
    }
    cout << endl;
}