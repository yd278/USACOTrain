#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("AcowdemiaIII.in","r",stdin);
        freopen("AcowdemiaIII.out","w",stdout);
    #endif
    int n,m,ans=0;
    cin>>n>>m;
    vector<string> a(n);
    map<vector<pair<int,int>>,int> p;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
            if(a[i][j]!='G') continue;
            vector<pair<int,int>>v;
            for(int d=0;d<4;d++){
                int x=i+dx[d],y=j+dy[d];
                if(x<0||x>=n||y<0||y>=m) continue;
                if(a[x][y]=='C')v.push_back({x, y});
            }
            if(v.size()<2)continue;
            if(v.size()>2)ans++;
            if(v.size()==2){
                if(v[0]>v[1])swap(v[0],v[1]);
                p[v]=1;
            }
        }
	}
    cout<<ans+p.size();
    return 0;


}
