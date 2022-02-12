#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000
int BIT[MAXN+1];
int n;

int lowbit(int x){
    return x & (-x);
}

void add(int x){
    while(x<=n){
        BIT[x]++;
        x+=lowbit(x);
    }
}

int sum(int x){
    int ans = 0;
    while(x){
        ans += BIT[x];
        x-= lowbit(x);
    }
    return ans;
}
int breed[MAXN+1];
int pre[MAXN+1];
int nxt[MAXN+1];

int main(){
    
    // #ifndef ONLINE_JUDGE
    //     freopen("UCFJ.in","r",stdin);
    //     freopen("UCFJ.out","w",stdout);
    // #endif
    cin>>n;
    long long cnt = 0;
    for(int i = 1; i <= n; i++){
        nxt[i] = n+1;
    }
    for(int i = 1; i <= n; i++){
        cin>>breed[i];
        if(pre[breed[i]]==0){
            add(i);
        }else{
            nxt[pre[breed[i]]] = i;
        }
        pre[breed[i]] = i;
    }
    for(int i = 1; i < n; i++){
        cnt += sum(nxt[i] - 1) - sum(i);
        if(nxt[i]!=n+1){
            add(nxt[i]);
        }
    }
    cout<<cnt<<endl;
    return 0;
}   