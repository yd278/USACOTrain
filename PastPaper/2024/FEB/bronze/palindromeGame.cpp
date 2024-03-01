#include <bits/stdc++.h>
using namespace std;

int main(){


	int n;
	cin>>n;
	string s;
	for(int i = 0; i < n; i++){
		cin>>s;
		if(s.back() == '0') cout<<"E\n";
		else cout<<"B\n";
	}
	return 0;
}
