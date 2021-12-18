/*
ID: dyh2191
LANG: C++14
TASK: holstein
*/

#include <iostream>
#include <vector>
using namespace std;

int V,G;
int req[26];
int scoop[16][26];
int acc[26];
int ansState;
int minCnt=2147483647;
vector<int> format;
int check(){
	for(int i = 0; i < V; i++){
		if(acc[i] < req[i])return 0;
	}
	return 1;
}
void dfs(int current,int cnt,int state){
	if(check()){
		if(cnt<minCnt){
			minCnt = cnt;
			ansState = state;
		}
		return;
	}
	if(current == G) return;

	//选
	for(int i = 0; i < V; i++){
		acc[i] += scoop[current][i];
	}
	dfs(current+1,cnt+1,state | (1<<current));
	for(int i = 0; i < V; i++){
		acc[i] -= scoop[current][i];
	}

	//不选
	dfs(current+1,cnt,state);

}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("holstein.in","r",stdin);
		freopen("holstein.out","w",stdout);
	#endif
	cin>>V;
	for(int i = 0; i < V; i++){
		cin>>req[i];
	}
	cin>>G;
	for(int i = 0; i < G; i++){
		for(int j = 0; j < V; j++){
			cin>>scoop[i][j];
		}
	}

	dfs(0,0,0);

	cout<<minCnt<<" ";

	for(int i = 0; i < G; i++){
		if(ansState & (1<<i)) format.push_back(i+1);
	}
	for(int i = 0; i < format.size() - 1; i++){
		cout<<format[i]<<" ";
	}
	cout<<*format.rbegin()<<endl;
	return 0;
}


