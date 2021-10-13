/*
ID: dyh2191
LANG: C++14
TASK: agrinet
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 101
#define MAXM 10005
using namespace std;

int flag[MAXN+10];
int getflag(int x){
	return x==flag[x]?flag[x]:flag[x]=getflag(flag[x]);
}

struct edge{
	int a,b,len;
    bool operator< (const edge &other) const{
        return len < other.len;
    }
};
vector <edge> edges;



int main(){
#ifndef ONLINE_JUDGE
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
#endif
	int n;
	cin>>n;
    int tmp;
	for(int i = 1; i<=n;i++){
		for(int j = 1; j <= n;j++){
            cin>>tmp;
            if(tmp!=0){
                edges.push_back(edge{i,j,tmp});
            }
        }
	}

	sort(edges.begin(),edges.end());

	int res = 0;
	for(int i = 0; i<n;i++){
		flag[i] = i;
	}
	for(auto e : edges){
		int x = e.a;
		int y = e.b;
		int fx = getflag(x);
		int fy = getflag(y);
		if(fx!=fy){
			res += e.len;
			flag[fx] = fy;
		}
	}
	cout<<res<<endl;
	return 0;
}
