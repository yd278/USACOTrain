#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int from,to,len;
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("BF.in","r",stdin);
		freopen("BF.out","w",stdout);
	#endif
	int n, m, s;
    cin >> n >> m >> s;
	vector<Edge> edges(m);
	for(auto &e : edges){
		cin>>e.from>>e.to>>e.len;
	}
	vector<int> dist(n+1, INT_MAX / 2);
	dist[s] = 0;
	for(int i = 0; i < n; i++){
		for(auto e : edges){
			//relax e
			if(dist[e.to] > dist[e.from]+e.len)
			dist[e.to] = dist[e.from] + e.len;
		}
	}
	
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

	return 0;
}
