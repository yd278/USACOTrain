#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edgesAL;
vector<int> label;

void dfs(int cur, int l){
    label[cur] = l;
    for(int to : edgesAL[cur]){
        if(!label[to])
            dfs(to,l);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("graphAlgos.in", "r", stdin);
    freopen("graphAlgos.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    edgesAL.resize(n + 1);
    label.resize(n + 1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edgesAL[a].push_back(b);
        edgesAL[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(label[i]==0){
            dfs(i,i);
        }
    }
    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>a>>b;
        if(label[a]==label[b]) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}
