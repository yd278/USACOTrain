#include <bits/stdc++.h>
using namespace std;
struct dept{
	int tDept;
	int target;
	int tAriv;
	bool operator< (const dept &other) const{
		if(tDept<other.tDept) return true;
		if(tDept==other.tDept){
			if(target< other.target)return true;
			if(target == other.target)
				if(tAriv < other.tAriv) return true;
		}
		return false;
	}
	
};
struct ariv{
	int city,time;
};
int main(){
	int n, m;
	cin>>n>>m;
	vector<set<dept>> depts(n+1);
	for(int i = 0; i < m; i++){
		int c,r,d,s;
		cin>>c>>r>>d>>s;
		depts[c].insert({r,d,s});
	}
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++)cin>>a[i];
	a[1] = 0;
	vector<int> earliest(n+1,INT_MAX);
	queue<ariv> q;
	q.push({1,0});
	while(!q.empty()){
		auto qh = q.front();
		q.pop();
		if(earliest[qh.city] > qh.time) earliest[qh.city] = qh.time;

		auto &ds = depts[qh.city];
		auto itLow = ds.lower_bound({qh.time+a[qh.city],0,0});
		for(auto it = itLow; it != ds.end();it++){
			q.push({it->target,it->tAriv});
		}
		ds.erase(itLow,ds.end());
	}
	for(int i = 1; i <= n; i++){
		if(earliest[i] == INT_MAX) earliest[i] = -1;
		cout<<earliest[i]<<endl;
	}
	return 0;
}
