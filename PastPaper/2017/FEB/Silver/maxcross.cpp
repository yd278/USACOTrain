#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("maxcross.in","r",stdin);
        freopen("maxcross.out","w",stdout);
    #endif
    int n,k,b;
    cin>>n>>k>>b;
    vector<int> sig(n);
    vector<int> sum(n+1);
    for(int i = 0; i < b; i++){
        int t;
        cin>>t;
        sig[t-1] = 1;
    }
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1]+sig[i-1];
    }
    int ans = INT_MAX;
    for(int i = k; i <= n; i++){
        if(sum[i]-sum[i-k]<ans) ans = sum[i] - sum[i-k];
    }
    cout<<ans<<endl;
}