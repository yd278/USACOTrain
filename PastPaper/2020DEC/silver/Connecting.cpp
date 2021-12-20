#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int id;

    vector<int> edges;
};
node nodes[100001];

int flag[100001];

long long D1[100001];
long long Dn[100001];
long long minD1,minDn;
void dfs(int x,int f){
    if(flag[x]!=-1)return;
    if(D1[x]<minD1)minD1 = D1[x];
    if(Dn[x] < minDn) minDn = Dn[x];
    node now = nodes[x];
    flag[x] = f;
    for(auto next : now.edges){
        dfs(next,f);
    }
}
void process() {
    int n, m;
    long long minAns = 29999800002;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        nodes[i].id = i;
        nodes[i].edges.clear();
        flag[i] = -1;
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        nodes[a].edges.push_back(b);
        nodes[b].edges.push_back(a);
    }
    dfs(1,1);

    if(flag[n]==1){
        cout<<0<<endl;
        return ;
    }
    int prev1 = 1;
    for(int i = 1; i <= n; i++){
        if(flag[i]==1){
            D1[i] = 0;
            prev1 = i;
        }
        else D1[i] = (long long)(i - prev1)*(i-prev1);
    }
    for(int i = n; i >= 1; i--){
        if(flag[i]==1){
            prev1 = i;
        }
        else{
            D1[i] = min(D1[i],(long long)(i-prev1)*(i-prev1));
        }
    }

    dfs(n,n);
    int prevn = n;
    for(int i = n; i >= 1; i--){
        if(flag[i]==n){
            prevn = i;
            Dn[i] = 0;
        }else{
            Dn[i] = (long long)(i-prevn)*(i-prevn);
        }
    }
    for(int i = 1; i <= n; i++){
        if(flag[i]==n){
            prevn = i;
        }else{
            Dn[i] = min(Dn[i],(long long)(i-prevn)*(i-prevn));
        }
    }
    
    
    
    int found = 0;
    for(int i = 1; i <=n; i++){
        if(flag[i]==-1){
            minD1 = 9999800002;
            minDn = 9999800002;
            
            dfs(i,i);
            if(minD1+minDn < minAns) {
            minAns = minD1+minDn;
            found = i;
            }
        }

    }
    if(found==0)cout<<1<<endl;
    else {
        for(int i = 2; i<=n; i++){
            if(flag[i]==1 && flag[i-1] ==n){
                cout<<1<<endl;
                return;
            }
            if(flag[i]==n && flag[i-1]==1){
                cout<<1<<endl;
                return;
            }
        }
        cout<<minAns<<endl;
    }
    
  

    return;
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("Connecting.in", "r", stdin);
//     freopen("Connecting.out", "w", stdout);
// #endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        process();
    }
    return 0;
}