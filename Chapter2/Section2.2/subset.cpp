/*
ID: dyh2191
LANG: C++14
TASK: subset
*/
#include <iostream>
using namespace std;
long long f[781];
int main() {
#ifndef ONLINE_JUDGE
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int m = n * (n + 1) / 2;
    if (m % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
	f[1] = 1;
    m /= 2;
    for (int i = 2; i <= n; i++) {
        for (int j = m; j >= i; j--) {
            f[j] += f[j - i];
        }
    }
    cout << f[m] / 2 << endl;
    return 0;
}