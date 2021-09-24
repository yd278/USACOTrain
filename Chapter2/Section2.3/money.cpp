/*
ID: dyh2191
LANG: C++14
TASK: money
*/
#include <iostream>
using namespace std;
int coins[26];
int N;
long long dp[10001];

int main() {
#ifndef ONLINE_JUDGE
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
#endif
    int v;
    cin >> v >> N;
    for (int i = 0; i < v; i++) cin >> coins[i];
    dp[0] = 1;
    for(int i = 0; i < v; i++){
        for(int j = coins[i]; j <=N; j++){
            dp[j] += dp[j-coins[i]]; 
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}