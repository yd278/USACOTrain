/*
ID: dyh2191
LANG: C++14
TASK: frac1
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct frac {
    int num, denom;
};
vector<frac> list;

int gcd(int a, int b) {  // assume b > a;
    if (a == 0) return b;
    return gcd(b % a, a);
}

int cmp(frac a, frac b) {
    double va = a.num / (double)a.denom;
    double vb = b.num / (double)b.denom;
	return va < vb;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("frac1.in","r",stdin);
		freopen("frac1.out","w",stdout);
	#endif
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(gcd(j,i)==1)
				list.push_back(frac{j,i});
		}
	}
	sort(list.begin(),list.end(),cmp);
	cout<<"0/1"<<endl;
	for(auto x : list){
		cout<<x.num<<"/"<<x.denom<<endl;
	}
	cout<<"1/1"<<endl;
	return 0;
}