#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("exercise.in","r",stdin);
        freopen("exercise.out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<bool> sieved(n+1);
    vector<long long> prime;
    for(int i = 2; i<=n; i++){
        if(!sieved[i])prime.push_back(i);
        for(int p : prime){
            if(i*p>n)break;
            sieved[i*p] = true;
            if(i%p==0) break;
        }
    }
    vector<vector<long long>> dp(prime.size()+1);
    for(auto &row :dp) row.resize(n+1);
    for(int i  = 0; i <= n; i++) dp[0][i] = 1;

    for(int i = 1; i<= prime.size(); i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = dp[i-1][j];
            long long p = prime[i-1];
            while(p<=j){
                dp[i][j] += dp[i-1][j-p]*p;
                if(dp[i][j]>=m)dp[i][j] %=m;
                p *= prime[i-1];
                if(p>=m) p%=m;
            }
        }
    }
    // int ans = 0;
    // for(int i = 0; i <=n; i++){
    //     ans += dp[prime.size()][i];
    //     if(ans>=m)ans%=m;
    // }
    cout<<dp[prime.size()][n]<<endl;
}