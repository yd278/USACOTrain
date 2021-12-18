/*
ID: dyh2191
LANG: C++14
TASK: numtri
*/

#include <iostream>
using namespace std;

int tri[1000][1000];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("numtri.in","r",stdin);
		freopen("numtri.out","w",stdout);
	#endif
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cin>>tri[i][j];
		}
	}

	for(int i = n - 2; i >= 0; i--){
		for(int j = 0; j <= i; j++){
			tri[i][j] += max(tri[i+1][j],tri[i+1][j+1]);
		}
	}
	cout<<tri[0][0]<<endl;
}