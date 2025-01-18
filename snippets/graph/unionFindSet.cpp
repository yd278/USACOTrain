#include<bits/stdc++.h>
using namespace std;
vector<int> flag;
int getFlag(int x){
    return x==flag[x]?x:flag[x]=getFlag(flag[x]);
}

bool check(int x, int y){
    int fx = getFlag(x);
    int fy = getFlag(y);
    return fx==fy;
}

void join(int x, int y){
    int fx = getFlag(x);
    int fy = getFlag(y);
    if(fx!=fy){
        flag[fx] = fy;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("unionFindSet.in","r",stdin);
        freopen("unionFindSet.out","w",stdout);
    #endif
    int n;
    cin>>n;
    flag.resize(n+1);
    for(int i = 1; i<=n; i++)flag[i] = i;

    return 0; 
}
