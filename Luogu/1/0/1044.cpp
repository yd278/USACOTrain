#include <iostream>
using namespace std;

long long f[19];

int n;
int main() {
#ifndef ONLINE_JUDGE
    freopen("1044.in", "r", stdin);
    freopen("1044.out", "w", stdout);
#endif
    cin >> n;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i] += f[j - 1] * f[i - j];
        }
    }
    cout << f[n] << endl;
}