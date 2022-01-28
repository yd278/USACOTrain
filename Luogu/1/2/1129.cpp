#include <iostream>
#include <vector>
using namespace std;

int match[201];
int vis[201];
vector<int> edges[201];
int dfs(int x){
    for(int to : edges[x]){
        if(!vis[to]){
            vis[to] = 1;
            if(match[to]==0){
                match[to] = x;
                return 1;
            } 
            if(dfs(match[to])){
                match[to] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("1129.in","r",stdin);
        freopen("1129.out","w",stdout);
    #endif
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i = 1; i<= n; i++){
            edges[i].clear();
            match[i] = 0;
        }
        int tmp;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin>>tmp;
                if(tmp){
                    edges[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                vis[j] = 0;
            }
            if(dfs(i))cnt++;
        }
        cout<<(cnt==n?"Yes":"No")<<endl;

    }
    return 0;
}