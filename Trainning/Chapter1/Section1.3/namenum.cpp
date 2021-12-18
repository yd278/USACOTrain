/*
ID: dyh2191
LANG: C++14
TASK: namenum 
*/

#include<vector>
#include<map>
#include <iostream>
#include <algorithm>
using namespace std;

map<long long,vector<string>> dict;
long long code(string name){
	long long result = 0;
	for(auto c : name){
		int shift = c - 'A';
		if(shift > 16) shift --;
		shift = (shift / 3) + 2;
		result = result * 10 + shift;
	}
	return result;
}
int main(){
	freopen("dict.txt","r",stdin);
	string name;
	while(cin>>name){
		long long serial = code(name);
		dict[serial].push_back(name);
	}
		freopen("namenum.in","r",stdin);
		freopen("namenum.out","w",stdout);
	cin.clear();

	long long num = 0;
	cin>>num;
	auto ans = dict[num];
	sort(ans.begin(),ans.end());
	for(auto ansName : ans){
		cout<<ansName<<endl;
	}
	if(ans.empty()){
		cout<<"NONE"<<endl;
	}
	return 0;
}