#include <bits/stdc++.h>
using namespace std;

int n;
int h[300001];
int k[300001];
long long f[300001];
long long g[300001];
struct item{
    int h,index;
};

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("frisbee.in","r",stdin);
    //     freopen("frisbee.out","w",stdout);
    // #endif
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>h[i];
    }
    stack<item> mono;
    mono.push(item{n+1,n});
    for(int i = n-1;i>=0;i--){
        while(mono.top().h<h[i])mono.pop();
        k[i] = mono.top().index;
        mono.push(item{h[i],i});
    }
    long long sum = 0;
    f[n-1] = 1;
    for(int i = n-1; i >=0; i--){
        f[i] = f[k[i]]+(long long)i;
    }
    for(int i = n-1; i>= 0; i--){
        g[i] = g[k[i]] + 1LL;
    }
    for(int i = 0; i < n - 1; i++){
        sum += f[i+1] - f[k[i]] + (k[i]==n?0LL:k[i]) - (g[i+1]-g[k[i]]+(k[i]==n?0LL:1LL))*(long long)(i-1); 
    }
    cout<<sum<<endl;
    return 0;
}

