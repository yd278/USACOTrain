#include<bits/stdc++.h>
using namespace std;
struct UFSet{
    vector<int> flag;
    UFSet(int n){
        flag = vector<int>(n+1);
        for(int i = 1; i <= n; i++) flag[i] = i;
    }
    int getFlag(int x){return x==flag[x]?x:flag[x]=getFlag(flag[x]);}
    void merge(int x, int y){
        int fx = getFlag(x);
        int fy = getFlag(y);
        if(fx!=fy){
            flag[fx] = fy;
        }
    }
    bool check(int x, int y){
        int fx = getFlag(x);
        int fy = getFlag(y);
        return fx == fy;

    }
};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("milkvisits.in","r",stdin);
        freopen("milkvisits.out","w",stdout);
    #endif 
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int x,y;
    UFSet u(n);
    for(int i = 0; i < n-1; i++){
        cin>>x>>y;
        if(s[x-1]==s[y-1]) u.merge(x,y);
    }

    char c;
    for(int i = 0; i < m; i++){
        cin>>x>>y>>c;
        if(u.check(x, y) && c!=s[x-1]) cout<<"0";
        else cout<<"1";
    }
    cout<<endl;

    return 0;
}
