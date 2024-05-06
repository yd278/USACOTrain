#include <bits/stdc++.h>
using namespace std;

int main(){
	// #ifndef ONLINE_JUDGE
	// 	freopen("cannonball.in","r",stdin);
	// 	freopen("cannonball.out","w",stdout);
	// #endif
	int n,s;
	cin>>n>>s;
	set<tuple<int,int,int>> visited;
	vector<int> q(n+1);
	vector<int> v(n+1);
	vector<bool> broken(n+1);
	for(int i = 1; i <= n; i++){
		cin>>q[i]>>v[i];
	}
	int pos = s;
	int dir = 1;
	int k = 1;
	int cnt = 0;
	while(pos >=1 && pos<=n){
		if(visited.find(make_tuple(pos,k,dir))!= visited.end()) break;
		visited.insert(make_tuple(pos,k,dir));
		if(q[pos] == 1){
			if(k >= v[pos]){ 
				if(!broken[pos])cnt++;
				broken[pos] = true;
			}
		}
		else{
			k += v[pos];
			dir *= -1;
		}
		pos += dir * k;
	}
	cout<<cnt<<endl;
	return 0;

}
