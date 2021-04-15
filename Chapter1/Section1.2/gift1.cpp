/*
ID: dyh2191
LANG: C++14
TASK: gift1
*/
#include <iostream>
#include <map>

using namespace std;

string order[11];
map<string, int> account;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("gift1.in","r",stdin);
		freopen("gift1.out","w",stdout);
	#endif
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>order[i];
		account[order[i]] = 0;
	}
	string name;
	int money, ng;
	string fri;
	for(int i = 0; i < n; i++){
		cin>>name;
		cin>>money>>ng;
		for(int j = 0; j < ng; j++){
			cin>>fri;
			account[fri] += money / ng;
			account[name] -= money / ng;
		}
	}

	for(int i = 0; i < n; i++){
		cout <<order[i]<<" "<< account[order[i]]<<endl;
	}
	return 0;
}