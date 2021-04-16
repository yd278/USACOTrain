/*
ID: dyh2191
LANG: C++14
TASK: transform
*/

/*
0: original
1: 90
2: 180
3: 270
4: reflect
5: reflect 90
6: reflect 180
7: reflect 270
8: target
*/

#include <iostream>
using namespace std;
int ans[8] = {6,1,2,3,4,5,5,5};
struct board{
	int content[11][11];
}
boards[9];
int n;
board readBoard(){
	string line;
	board b;
	for(int i = 0; i < n; i++){
		cin>> line;
		for(int j = 0; j < n; j++){
			b.content[i][j] = line[j]== '@';
		}
	}
	return b;
}

board rotate(board origin){
	board target;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			target.content[i][n - j - 1] = origin.content[j][i];
		}
	}
	return target;
}

board reflect(board origin){
	board target;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			target.content[i][n - j - 1] = origin.content[i][j];
		}
	}
	return target;
}
int equal(board a, board b){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a.content[i][j]!=b.content[i][j])return false;
		}
	}
	return true;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("transform.in","r",stdin);
		freopen("transform.out","w",stdout);
	#endif
	string line;
	cin>>n;
	boards[0] = readBoard();
	boards[8] = readBoard();
	
	for(int i = 1; i < 4; i++)
		boards[i] = rotate(boards[i - 1]);
	
	for(int i = 4; i < 8; i++)
		boards[i] = reflect(boards[i - 4]);

	for(int i = 1; i < 8; i++){
		if(equal(boards[i],boards[8])){
			cout<<ans[i]<<endl;
			return 0;
		}
	}
	cout<<7<<endl;
	return 0;
	

}