#include <bits/stdc++.h>
using namespace std;

vector<long long> x,y,p;
vector<vector<int>> edges;
inline long long sqr(long long x){
    return x * x;
}
vector<int> visited;
int dfs(int x){
    visited[x] = 1;
    int sum = 0;
    for(int to : edges[x]){
        if(!visited[to]) sum += dfs(to);
    }
    return sum + 1;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("moocast.in","r",stdin);
        freopen("moocast.out","w",stdout);
    #endif
    int n;
    cin>>n;
    x.resize(n);
    y.resize(n);
    p.resize(n);
    visited.resize(n);
    edges.resize(n);
    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i]>>p[i];
        p[i] = sqr(p[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j==i)continue;
            long long sqrDist = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
            if(sqrDist <= p[i])edges[i].push_back(j);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) visited[j] =0;
        int r = dfs(i);
        if(r > res) res = r;
    }
    cout<<res<<endl;
    return 0;

}