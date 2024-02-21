#include <bits/stdc++.h>
using namespace std;

inline void print(const vector<int> &ans){
	for(int t : ans){
		cout<<"    "<<t+1;
	}
	cout<<"\n";
}
void dfs(int cur, int n, vector<bool> &used, vector<int> &ans){
	if(cur == n){
		print(ans);
	}
	for(int i = 0; i < n; i++){
		if(!used[i]){
			ans[cur] = i;
			used[i] = true;
			dfs(cur+1,n,used,ans);
			used[i] = false;
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("1706.in","r",stdin);
		freopen("1706.out","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<bool> used(n);
	vector<int> ans(n);
	dfs(0,n,used,ans);

	return 0;
}
