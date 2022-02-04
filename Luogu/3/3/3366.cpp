#include <iostream>
#include <algorithm>

#define MAXN 5000
#define MAXM 200000
using namespace std;

int flag[MAXN+10];
int getflag(int x){
	return x==flag[x]?flag[x]:flag[x]=getflag(flag[x]);
}

struct edge{
	int a,b,len;
}edges[MAXM+10];

bool cmp(const edge& a,const  edge& b){
	return (a.len) < (b.len);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("3366.in","r",stdin);
    freopen("3366.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	for(int i = 0; i<m;i++){
		cin>>edges[i].a>>edges[i].b>>edges[i].len;
	}

	sort(&edges[0],&edges[m],cmp);

	int res = 0;
	for(int i = 0; i<n;i++){
		flag[i] = i;
	}
    int cnt = 0;
	for(int i = 0; i < m; i++){
		int x = edges[i].a;
		int y = edges[i].b;
		int fx = getflag(x);
		int fy = getflag(y);
		if(fx!=fy){
			res += edges[i].len;
			flag[fx] = fy;
            cnt++;
		}
        if(cnt==n-1)break;
	}
    if(cnt==n-1)
        cout<<res<<endl;
    else
        cout<<"orz"<<endl;
	return 0;
}
