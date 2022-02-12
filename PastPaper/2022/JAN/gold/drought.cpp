#include <bits/stdc++.h>
using namespace std;
int f[2][1001][1001];
int h[100];
int sum[1002];
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("drought.in", "r", stdin);
//     freopen("drought.out", "w", stdout);
// #endif
    int n;
    cin >> n;
    int mini = 10000;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (h[i] < mini) mini = h[i];
    }
    for (int j = 0; j <= h[0]; j++) {
        for (int k = 0; k <= h[0]; k++) {
            f[0][j][k] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        int ii = i % 2;
        int ip = (i-1) % 2;
        for(int j = 0; j < 1001; j++)
            for(int k = 0; k < 1001; k++)
                f[ii][j][k] = 0;
        for (int j = 0; j <= h[i]; j++) {
            int sum = 0;
            for (int k = h[i]; k >= j; k--) {
                sum += f[ip][j][j - k + h[i]];
                if (sum > 1000000007) sum %= 1000000007;
                f[ii][j][k] = sum;
            }
        }
    }
    int ans = 0;
    
    for (int j = 0; j <= mini; j++) {
        ans += f[(n - 1)%2][j][j];
        if (ans > 1000000007) ans %= 1000000007;
    }
    cout << ((n&1)?ans:f[(n-1)%2][0][0]) << endl;
    return 0;
}