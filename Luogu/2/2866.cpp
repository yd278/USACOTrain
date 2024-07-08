#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("2866.in","r",stdin);
		freopen("2866.out","w",stdout);
	#endif
	stack<int> s;
	long long ans = 0;
	int n;
	cin>>n;
	int h;
	for(int i = 0; i < n; i++){
		cin>>h;
		while(!s.empty() && s.top()<=h) s.pop();
		ans += s.size();
		s.push(h);
	}
	cout<<ans;
	return 0;
}
