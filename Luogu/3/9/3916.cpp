#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> edges;
vector<int> A;
void dfs(int cur, int lab){
    A[cur] = lab;
    for(int to : edges[cur]){
        if(A[to]) continue;
        dfs(to,lab);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("3916.in","r",stdin);
        freopen("3916.out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    edges.resize(n+1);
    A.resize(n+1);
    int a,b;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        edges[b].push_back(a);
    }
    for(int i = n; i>=1;i--){
        if(!A[i]) dfs(i,i);
    }

    for(int i = 1; i <= n; i++){
        cout<<A[i]<<" ";
    }

    return 0;
}
