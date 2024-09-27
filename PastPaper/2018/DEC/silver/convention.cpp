#include <bits/stdc++.h>
using namespace std;
bool check(int mid, vector<int> &t,int m, int c){
	int firstCow = 0;
	int cntBus = 1;
	for(int i = 1; i < t.size();i++){
		if(t[i]>t[firstCow]+mid){
			cntBus ++;
			firstCow = i;
		}else if(i-firstCow == c){
			cntBus++;
			firstCow = i;
		}
		if(cntBus > m) return false;
	}
	return true;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("convention.in","r",stdin);
		freopen("convention.out","w",stdout);
	#endif
	int n,m,c;
	cin>>n>>m>>c;
	vector<int> t(n);
	for(auto &x : t) cin>>x;
	sort(t.begin(),t.end());
	int l = 0;
	int r = t.back();
	while(l!=r){
		int mid = (l+r) / 2;
		if(check(mid, t, m,c)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	cout<<l<<endl;

	return 0;
}
