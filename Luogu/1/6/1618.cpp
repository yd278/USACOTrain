#include <bits/stdc++.h>
using namespace std;
vector<int> rec(9);
int a,b,c;
int num1, num2, num3;
bool flag;
vector<bool> used(10);
void dfs(int n){
	if(n==9){
		num3 = 0;
		for(int i = 6; i < 9; i++){
			num3 = num3*10+rec[i];
		}
		if(num3 % c != 0) return;
		if(num3 / c == num1/a) {
			cout<<num1<<" "<<num2<<" "<<num3<<endl;
			flag = true;
		}
		return;
	}

	if(n==6){
		num2 = 0;
		for(int i = 3; i < 6; i++){
			num2 = num2*10+rec[i];
		}
		if(num2 % b != 0) return;
		if(num2 / b != num1/a) return;
	}

	if(n==3){
		num1 = 0;
		for(int i = 0; i < 3; i++){
			num1 = num1*10+rec[i];
		}
		if(num1 % a != 0) return;
	}
	for(int i = 1; i <= 9; i++){
		if(!used[i]){
			used[i] = true;
			rec[n] = i;
			dfs(n+1);
			used[i] = false;
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("1618.in","r",stdin);
		freopen("1618.out","w",stdout);
	#endif

	cin>>a>>b>>c;
	if(a==0) {
		cout<<"No!!!"<<endl;
		return 0;
	}
	dfs(0);
	if(!flag) 
		cout<<"No!!!"<<endl;
	return 0;
}
