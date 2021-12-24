#include <iostream>
#include <algorithm>
using namespace std;

int X[100001];
int Y[100001];
int flag[100001];
int tail;
int N;
int getFlag(int x){
	return flag[x]==x?x:flag[x]=getFlag(flag[x]);
}
int uni(int x, int y){
	int fx = getFlag(x);
	int fy = getFlag(y);
	if(fx!=fy){
		flag[fx] = fy;
	}
}

void sort(int l, int r){
	int i = l, j = r;
	int x = X[(l+r)/2];
	int y = Y[(l+r)/2];
	while(i<=j){
		while(X[i]<x||(X[i]==x&&Y[i]<y))i++;
		while(X[j]>x||(X[j]==x&&Y[j]>y))j--;
		if(i<=j){
			int tmp = X[i];
			X[i] = X[j];
			X[j] = tmp;

			tmp = Y[i];
			Y[i] = Y[j];
			Y[j] = tmp;
			i++;
			j--;
		}
	}
	if(i < r) sort(i,r);
	if(l < j) sort(l,j);
}
int Min[100001];
int Max[100001];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("moop.in","r",stdin);
		freopen("moop.out","w",stdout);
	#endif
	cin>>N;
	for(int i = 0 ; i < N; i ++){
		cin>>X[i]>>Y[i];
	
	}
	sort(0,N-1);
	Min[0] = Y[0];
	for(int i = 1; i < N; i++){
		Min[i] = min(Min[i-1],Y[i]);
	}

	Max[N-1] = Y[N-1];
	for(int i = N - 2; i >= 0; i--){
		Max[i] = max(Max[i+1],Y[i]);
	}

	int cnt = 1;
	for(int i = 0; i < N - 1; i++){
		if(Min[i]>Max[i+1]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
}