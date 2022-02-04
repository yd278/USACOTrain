#include <iostream>
#include <vector>
using namespace std;
#define MAXN 10005
#define MAXM 500005
struct Edge{
	int to,len;
};
#define MAX_INT 2147483647
vector<Edge> edges[MAXN];
int dist[MAXN];
int isIn[MAXN];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("3371.in","r",stdin);
		freopen("3371.out","w",stdout);
	#endif
	int n,m,s;
	cin>>n>>m>>s;
	int a,b,c;
	for(int i = 0; i < m; i++){
		cin>>a>>b>>c;
		Edge tmp = {b,c};
		edges[a].push_back(tmp);
	}

	for(int i = 1;i<=n;i++){
		dist[i] = MAX_INT;
	}

	isIn[s] = 1;
    dist[s] = 0;
	for(auto edge : edges[s]){	
            int to = edge.to;
            int len = edge.len;
			if(dist[to]>len){
				dist[to] =  len;
			}
	}

	for(int i = 1; i < n;i++){

		
		int min=MAX_INT,minID;
		for(int j = 1; j <= n; j++){
			if(!isIn[j]){
				if(dist[j]<min){
					min = dist[j];
					minID = j;
				}
			}
		}

		isIn[minID] = 1;
		for(auto edge : edges[minID]){
			int to = edge.to;
			int len = edge.len;
			if(dist[to]>dist[minID]+len){
				dist[to] = dist[minID] + len;
			}
		}

	}

	for(int i = 1;i <=n; i++){
		cout<<dist[i]<<" ";
	}

}
