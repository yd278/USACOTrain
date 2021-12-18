/*
ID: dyh2191
LANG: C++14
TASK: rockers
*/
#include <iostream>
using namespace std;
int N,T,M;
int len[20];
int maxN = 0;
void dfs(int x, int t, int m, int res){ // x: 正在搜的歌号， t 这张碟还剩的时间， m用的碟数量， res 已经放进去的歌数
    if(x==N){
        if(res > maxN) maxN = res;
        return ;
    }
    if(len[x] <= t) dfs(x+1,t-len[x],m,res+1);//同一张
    if(len[x] <= T && m<M) dfs(x+1,T-len[x],m+1, res+1);//下一张
    dfs(x+1,t,m,res);//不放
    
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("rockers.in","r",stdin);
        freopen("rockers.out","w",stdout);
    #endif
    cin>>N>>T>>M;
    for(int i = 0; i < N; i++){
        cin>>len[i];
    }
    dfs(0,T,1,0);
    cout<<maxN<<endl;
    
}