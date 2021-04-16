/*
ID: dyh2191
LANG: C++14
TASK: palsquare
*/

#include <iostream>
using namespace std;

int check(string num){
	int n = num.size();
	for(int i = 0; i < n / 2; i++){
		if(num[i]!=num[n - i - 1]) return false;
	} 
	return true;
}

string convert(int x,int b){
	string res = "";
	while(x){
		char d = '0' + x % b;
		if(d > '9') d = d - '9' + 'A' - 1;
		res = d + res;
		x /= b;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("palsquare.in","r",stdin);
		freopen("palsquare.out","w",stdout);
	#endif
	int b;
	cin>>b;
	for(int i = 1; i <= 300; i++){
		int ii = i * i;
		if(check(convert(ii,b))){
			cout<<convert(i,b)<<" "<<convert(ii,b)<<endl;
		}
	}
	return 0;
}