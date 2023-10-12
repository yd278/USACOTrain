#include <bits/stdc++.h>
using namespace std;
struct dept{
	int t_dept;
	int target;
	int t_ariv;
	bool operator< (const dept &other) const{
		if(t_dept<other.t_dept) return true;
		if(t_dept==other.t_dept){
			if(target< other.target)return true;
			if(target == other.target)
				if(t_ariv < other.t_ariv) return true;
		}
		return false;
	}
	
};
struct ariv{
	int city,time;
};
int main(){
#ifndef ONLINE_JUDGE
	freopen("mooRoute.in","r",stdin);
	freopen("mooRoute.out","w",stdout);
#endif
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
	vector<int> earist(n+1,INT_MAX);
	queue<ariv> q;
	q.push({1,0});
	while(!q.empty()){
		auto qh = q.front();
		q.pop();
		if(earist[qh.city] > qh.time) earist[qh.city] = qh.time;
		#define ds depts[qh.city]
		auto itlow = ds.lower_bound({qh.time+a[qh.city],0,0});
		for(auto it = itlow; it != ds.end();it++){
			q.push({it->target,it->t_ariv});
		}
		ds.erase(itlow,ds.end());
	}
	for(int i = 1; i <= n; i++){
		if(earist[i] == INT_MAX) earist[i] = -1;
		cout<<earist[i]<<endl;
	}
	return 0;
}
