#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<long long> a;
	vector<long long> diff;

	int n;

	cin>>n;
	a.resize(n);
	for(auto &g: a){
		cin>>g;
	}
	diff.resize(n);  //diff[i] = a[i] - a[i-1]
	diff[0] = a[0];
	for(int i = 1; i < n; i ++){
		diff[i] = a[i] - a[i-1];
	}

	long long sum = abs(diff[0]);
	for(int i = 1; i < n; i++){
		sum += abs(diff[i] - diff[i-1]);
	}
	cout<<sum<<endl;

	return 0;
}
