/*
ID: dyh2191
LANG: C++14
TASK: ride
*/
#include <iostream>

using namespace std;
int num(string x){
	int res = 1;
	for(auto c : x){
		res *= (c - 'A' + 1);
	}
	return res % 47;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
#endif
	string a,b;
	cin >> a;
	cin >> b;
	if(num(a)==num(b))
		cout<<"GO"<<endl;
	else
		cout<<"STAY"<<endl;
	return 0;
}