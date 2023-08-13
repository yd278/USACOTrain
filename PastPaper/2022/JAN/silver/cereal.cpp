#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define MAXM 200000

int match[MAXM+1];
int first[MAXN+1];
int second[MAXN+1];
int selected[MAXN+1];
int follow[MAXN+1];
int inCnt[MAXN+1];
int visited[MAXN+1];
int dfs(int x,map<int,int> &vis){
    int to = first[x];
    if(!vis[to]){
        vis[to] = 1;
        if(!match[to]){
            match[to] = x;
            selected[x] = to;
            return 1;
        }
        if(dfs(match[to],vis)){
            match[to] = x;
            selected[x] = to;
            return 1;
        }
    }
    to = second[x];
    if(!vis[to]){
        vis[to] = 1;
        if(!match[to]){
            match[to] = x;
            selected[x] = to;
            return 1;
        }
        if(dfs(match[to],vis)){
            match[to] = x;
            selected[x] = to;
            return 1;
        }
    }
    return 0;

}

void check(int i){
    if(visited[i])return;
    visited[i] = 1;
    if(follow[i]==0){
        cout<<i<<endl;
        return;
    }
    check(follow[i]);
    cout<<i<<endl;
}
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("cereal.in","r",stdin);
    //     freopen("cereal.out","w",stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>first[i]>>second[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        map<int,int>vis;
        if(dfs(i,vis))cnt++;
    }
    cout<<n-cnt<<endl;
    for(int i = 1; i < n; i++){
        if(selected[i]==first[i]){
            cout<<i<<endl;
            visited[i] = 1;
        }else{
            follow[i] = match[first[i]];
            inCnt[follow[i]]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]&&inCnt[i] == 0){
            check(i);
        }
    }

    return 0;


}