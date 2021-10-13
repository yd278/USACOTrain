/*
ID: dyh2191
LANG: C++14
TASK: stamps
*/
#include <iostream>
using namespace std;

int f[2000000];
int values[50];
int main() {
#ifndef ONLINE_JUDGE
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
#endif
    int k, n;
    cin >> k >> n;
    int max_value = 0;
    for (int i = 0; i < n; i++) {
        cin >> values[i];
        max_value = max(max_value, values[i]);
    }
    f[0] = 0;
    for (int i = 1; i <= max_value * k; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= values[j]) {
                int tmp = f[i - values[j]] + 1;
                f[i] = (f[i] == 0) ? tmp : min(f[i], tmp);
            }
        }
        if (f[i] > k) {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << max_value * k << endl;
    return 0;
}