#include <bits/stdc++.h>
using namespace std;
#define MAXN 5000
#define MOD 80112002
vector<int> edges[MAXN + 1];
int inDegree[MAXN + 1];
int f[MAXN + 1];
vector<int> consumer;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("4017.in","r",stdin);
        freopen("4017.out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        edges[a].push_back(b);
        inDegree[b] ++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(edges[i].size()==0){
            consumer.push_back(i);
        }
        if(inDegree[i]==0){
            q.push(i);
            f[i] = 1;
        }
    }
    while(!q.empty()){
        int h = q.front();
        q.pop();
        for(auto e : edges[h]){
            f[e] += f[h];
            if(f[e]>= MOD) f[e]%=MOD;
            inDegree[e]--;
            if(inDegree[e]==0){
                q.push(e);
            }
        }
    }
    int sum = 0;
    for(auto x : consumer){
        sum += f[x];
        if(sum >= MOD) sum%= MOD;
    }
    cout<<sum<<endl;
    return 0;
}