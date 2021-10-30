/*
ID: dyh2191
LANG: C++14
TASK: nuggets
*/
#include <iostream>
using namespace std;
#define MAXN 65536
int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
int dp[MAXN + 1];
int nug[10];
int main() {
#ifndef ONLINE_JUDGE
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);
#endif
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nug[i];
    }
    int flag = nug[0];
    for (int i = 1; i < n; i++) {
        flag = gcd(flag, nug[i]);
    }
    if (flag != 1) {
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = nug[i]; j <= MAXN; j++) {
            dp[j] |= dp[j - nug[i]];
        }
    }
    for (int j = MAXN; j >= 0; j--) {
        if (!dp[j]) {
            cout << j << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}