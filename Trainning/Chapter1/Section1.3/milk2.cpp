/*
ID: dyh2191
LANG: C++14
TASK: milk2
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int Begin[5001];
int End[5001];

stack<int> s;
int maxMilk = 0;
int maxIdle = 0;
inline void updateMilk(int x){ maxMilk = max(maxMilk,x);}
inline void updateIdle(int x){ maxIdle = max(maxIdle,x);}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("milk2.in","r",stdin);
		freopen("milk2.out","w",stdout);
	#endif
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>Begin[i]>>End[i];
	}
	sort(Begin,Begin + n);
	sort(End,End + n);
	Begin[n] = 1000001;
	End[n] = 1000001;
	int prev = Begin[0];
	int b = 0;
	int e = 0;
	while(b < n || e < n){
		if(Begin[b] <= End[e]){
			if(s.empty()){	
				updateIdle(Begin[b] - prev);
			}
			s.push(Begin[b]);
			b++;
		}else{
			int tmp = s.top();
			s.pop();
			if(s.empty()){
				updateMilk(End[e] - tmp);
				prev = End[e];
			}
			e++;
		}
	}
	cout<<maxMilk<<" "<<maxIdle<<endl;
	return 0;

}