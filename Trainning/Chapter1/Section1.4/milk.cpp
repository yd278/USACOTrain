/*
ID: dyh2191
LANG: C++14
TASK: milk
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct farmer{
	int p,a;
} farmers[5001];

int cmp(farmer x, farmer y){
	return x.p < y.p;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("milk.in","r",stdin);
		freopen("milk.out","w",stdout);
	#endif
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> farmers[i].p >> farmers[i].a;
	}
	sort(farmers, farmers + m, cmp);
	int i = 0;
	int res = 0;
	while(n){
		if(n < farmers[i].a){
			res += farmers[i].p * n;
			break;
		}
		n -= farmers[i].a;
		res += farmers[i].p * farmers[i].a;
		i++;
	}
	cout<<res<<endl;
}