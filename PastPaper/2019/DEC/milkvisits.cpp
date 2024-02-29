#include <iostream>
#include <vector>

using namespace std;
#define MAXN 100050
#define MAXM 100050

vector <int> querys[MAXN];
vector <int> edges[MAXN];
int ans[MAXM];
int prevTop[MAXM];
int visited[MAXN];

int top[MAXN];
int fColors[MAXN];
int qColors[MAXM];

void dfs(int x, int p){
	int currentColor = fColors[x];
	int tmp = top[currentColor];
	for(auto qID : querys[x]){
		int qColor = qColors[qID];
		if(!visited[qID]){
			prevTop[qID] = top[qColor];
			visited[qID] = 1;
		}else{
			ans[qID] = (top[qColor]!=prevTop[qID]);
		}
	}
	for(auto next : edges[x]){
		if(next == p) continue;
		top[currentColor] = next;
		dfs(next,x);
	}
	top[currentColor]=tmp;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("milkvisits.in","r",stdin);
		freopen("milkvisits.out","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>fColors[i];
	int a,b;
	for(int i = 0; i < n - 1; i++){
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int c;
	for(int i = 0; i < m; i++){
		cin>>a>>b>>c;
		if(fColors[a]==c||fColors[b]==c)ans[i]=1;
		else{
			qColors[i] = c;
			querys[a].push_back(i);
			querys[b].push_back(i);
		}
	}

	dfs(1,0);
	for(int i = 0; i < m;i++){
		cout<<ans[i];
	}
}