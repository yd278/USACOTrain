#include <iostream>
using namespace std;
int a[20];
int n,k;
int prime(int n){
    for(int i = 2; i * i <=n; i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int ans;
void pick(int i, int cnt, int sum){
    if(cnt==k){
        if(prime(sum))ans++;
        return;
    }
    if(i==n) return;
    pick(i+1,cnt+1,sum+a[i]);
    pick(i+1,cnt,sum);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1036.in","r",stdin);
    freopen("1036.out","w",stdout);
#endif
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    pick(0,0,0);
    cout<<ans<<endl;
}