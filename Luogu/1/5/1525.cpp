#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;

int flag[40000];
struct Pair{
    int a,b,c;
    bool operator< (const Pair &other) const{
        return c>other.c;
    }
};
vector<Pair> pairs;
int getflag(int x){
	return x==flag[x]?x:flag[x]=getflag(flag[x]);
}

int check(int x, int y){
	int fx = getflag(x);
	int fy = getflag(y);
	return (fx == fy);
}

void uni(int x, int y){
	int fx = getflag(x);
	int fy = getflag(y);
	if(fx!=fy){
		flag[fx] = fy;
	}
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("1525.in","r",stdin);
    freopen("1525.out","w",stdout);
#endif
	cin>>n>>m;
	
	for(int i = 0; i < 2*n; i++){
		flag[i] = i;
	}
    int a,b,c;
	for(int i = 0; i<m;i++){
        cin>>a>>b>>c;
		pairs.push_back(Pair{a,b,c});
	}

	sort(pairs.begin(),pairs.end());

	for(auto p : pairs){
		int fst = p.a;
		int sec = p.b;
		if(check(fst,sec)){
			cout<<p.c<<endl;
			return 0;
		}
		else{
			uni(fst,sec+n);
			uni(sec,fst+n);
		}
	}
	printf("0\n");


}