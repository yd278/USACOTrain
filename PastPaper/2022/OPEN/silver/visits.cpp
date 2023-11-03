#include <bits/stdc++.h>
using namespace std;


vector<int> a;
vector<long long> p;
queue <int> q;
vector<int> inDeg;
vector<bool> vis;
long long minP;

int main(){
	int n;
	cin>>n;
	a.resize(n+1);
	p.resize(n+1);
	inDeg.resize(n+1);
	vis.resize(n+1);
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		cin>>a[i]>>p[i];
		inDeg[a[i]]++;
		sum+=p[i];
	}
	for(int i = 1; i <= n; i++){
		if(!inDeg[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		auto h = q.front();
		q.pop();
		vis[h] = true;
		inDeg[a[h]]--;
		if(!inDeg[a[h]])q.push(a[h]);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			minP = p[i];
			for(int x = i; !vis[x]; x = a[x]){
				minP = min(minP,p[x]);
				vis[x] = true;
			}
			sum -= minP;
		}
	}
	cout<<sum<<endl;



	return 0;
}
