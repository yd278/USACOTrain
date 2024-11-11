#include<bits/stdc++.h>
using namespace std;
struct edge{
    int from, to;
};
vector<edge>edgesEL;

vector<vector<int>> edgesAL;
vector<vector<int>> adjMat;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("graphStorage.in","r",stdin);
        freopen("graphStorage.out","w",stdout);
    #endif
    int n, m;
    cin >> n >> m;
    edgesAL.resize(n + 1);
    edgesEL.resize(m);
    adjMat.resize(n+1,vector<int>(n+1));
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        
        //adjacent list
        edgesAL[a].push_back(b);
        edgesAL[b].push_back(a);
        //Edge List
        edgesEL.push_back({a,b});
        edgesEL.push_back({b,a});

        //adjacent matrix
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }


    return 0;
}
