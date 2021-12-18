/*
ID: dyh2191
LANG: C++14
TASK: beads
*/
#include<iostream>
using namespace std;

int right_red[701];
int left_red[701];
int right_blue[701];
int left_blue[701];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("beads.in","r",stdin);
		freopen("beads.out","w",stdout);
	#endif
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i = 1; i <= 2 * n; i++){
		char c = s[(i - 1) % n];
		if(c == 'r'){
			left_red[i] = left_red[i - 1] + 1;
			left_blue[i] = 0;
		} else if(c == 'b'){
			left_red[i] = 0;
			left_blue[i] = left_blue[i - 1] + 1;
		} else{
			left_red[i] = left_red [i - 1] + 1;
			left_blue[i] = left_blue[i - 1] + 1;
		}
	}

	for(int i = 2 * n - 1; i >= 0; i--){
		char c = s[i % n];
		if(c == 'r'){
			right_red[i] = right_red[i + 1] + 1;
			right_blue[i] = 0;
		}else if (c == 'b'){
			right_red[i] = 0;
			right_blue[i] = right_blue[i + 1] + 1;
		}else{
			right_red[i] = right_red[i + 1] + 1;
			right_blue[i] = right_blue[i + 1] + 1;
		}
	}
	int max = 0;
	for(int i = 0; i <= 2 * n; i ++){
		if(left_blue[i] + right_red[i] > max)
			max = left_blue[i] + right_red [i];
		if(right_blue[i] + left_red[i] > max)
			max = right_blue[i] + left_red[i];
	}
	if(max > n) max = n;
	cout<<max<<endl;
	return 0;
}