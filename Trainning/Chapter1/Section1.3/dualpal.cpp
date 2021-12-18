/*
ID: dyh2191
LANG: C++14
TASK: dualpal
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
int checkDual(int x){
	int cnt = 0;
	for(int b = 2; b <= 10; b++){
		if(check(convert(x,b))) cnt++;
		if(cnt >= 2) return true;
	}
	return false;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("dualpal.in","r",stdin);
		freopen("dualpal.out","w",stdout);
	#endif
	int n,s;
	cin>>n>>s;
	int cnt = 0;
	while(cnt < n){
		s++;
		if(checkDual(s)){
			cout<<s<<endl;
			cnt++;
		}
	}
	return 0;
}