/*
ID: dyh2191
LANG: C++14
TASK: hamming
*/
#include <iostream>
using namespace std;

int count(int x) {
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
    x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
    x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
    return x;
}
int ans[65];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("hamming.in","r",stdin);
		freopen("hamming.out","w",stdout);
	#endif
	int n,b,d;
	cin>>n>>b>>d;
	int top = 0;
	for(int p = 0;p < (1<<b); p++){
		int check = 1;
		for(int i = 0; i < top; i++){
			if(count(p^ans[i])<d){
				check = 0;
				break;
			}
		}
		if(check){
			ans[top++] = p;
		}
		if(top == n) break;
	}

	for(int i = 0; i < n - 1; i++){
		if(i % 10 == 9) cout<<ans[i]<<endl;
		else cout<<ans[i] <<" ";
	}
	cout<<ans[n-1]<<endl;
}