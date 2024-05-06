#include <bits/stdc++.h>
using namespace std;

void process(){
	int n;
	cin>>n;
	vector<int> prev(n+1,-1);
	vector<int> shortest(n+1,INT_MAX);
	int a;
	for(int i = 0; i < n; i++){
		cin>>a;
		int p = prev[a];
		int gap = i - p - 1;
		if(p != -1){
			if(shortest[a] > gap) shortest[a] = gap;
		}
		prev[a] = i;
	}
	vector<int> ans;
	for(int i = 1; i<= n; i++){
		if(shortest[i]<=1) ans.push_back(i);
	}
	if(ans.size()==0)cout<<"-1\n";
	else{
		for(int i = 0; i < ans.size() - 1; i++){
			cout<<ans[i]<<" ";
		}
		cout<<ans.back()<<endl;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("majorityOpinion.in","r",stdin);
		freopen("majorityOpinion.out","w",stdout);
	#endif
	//如果一种草间隔<2则可行
	//否则不行
	int t;
	cin>>t;
	while(t--){
		process();
	}
	return 0;
}
