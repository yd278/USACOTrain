#include <iostream>
#include <vector>
using namespace std;
vector<vector <int>> edges;
vector<vector<int>> pr;
vector<int> dep;

void dfs(int now,int depth){
	dep[now] = depth;
	for(auto to:edges[now]){
		if(to != pr[0][now]){
			pr[0][to] = now;
			dfs(to,depth+1);
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("lca.in","r",stdin);
		freopen("lca.out","w",stdout);
	#endif
	int n,m,s;
	cin>>n>>m>>s;
	int log = 0;
	while((1<<log)<n)log++;
	edges.resize(n+1);
	pr.resize(log);
	pr[0].resize(n+1);
	dep.resize(n+1);
	int a,b;
	for(int i = 0; i<n-1; i++){
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(s,1);
	for(int i = 1; i < log;i++){
		pr[i].resize(n+1);
		for(int j = 1; j <=n;j++){
			pr[i][j] = pr[i-1][pr[i-1][j]];
		}
	}
	for(int i = 0; i<m;i++){
		cin>>a>>b;
		if(dep[a]<dep[b])swap(a,b);

		int shift = dep[a]-dep[b];
		for(int j = 0; (1<<j)<=shift;j++){
			if((1<<j)&shift) a = pr[j][a];
		}
		if(a==b)cout<<a<<endl;
		else{
			for(int j = log-1;j>=0;j--){
				if(pr[j][a]!=pr[j][b]){
					a = pr[j][a];
					b = pr[j][b];
				}
			}
			
			cout<<pr[0][a]<<endl;
		}
	}
	return 0;
}




