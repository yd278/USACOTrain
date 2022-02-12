#include<iostream>
using namespace std;

int to[200005];
int nxt[200005];
int from[100005];
int e_tail;

void addedge(int a,int b){
	to[++e_tail] = b;
	nxt[e_tail] = from[a];
	from[a] = e_tail;
	to[++e_tail] = a;
	nxt[e_tail] = from[b];
	from[b] =e_tail;
}
int par[100005];
int log(int x){
	int i = 0;
	while((1<<i)<x){
		i++;
	}
	return i;
}
int dfs(int x){

	int sum = 0;
	int cnt = 0;
	for(int e = from[x];e;e=nxt[e]){
		int y = to[e];
		if(y!=par[x]){
			par[y] = x;
			sum += dfs(y);
			cnt++;
		}
	}
	return sum +cnt +  log(cnt+1);

} 

int main(){

	int n;
	cin>>n;
	int a,b;
	for(int i = 0 ; i<n-1; i++){
		cin>>a>>b;
		addedge(a,b);
	}
	cout<<dfs(1)<<endl;
	return 0;

}