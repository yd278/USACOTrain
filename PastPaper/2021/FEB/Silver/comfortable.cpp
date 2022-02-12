#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int N;
bool cont[3000][3000];
vector<pair<int, int>> newc;
int countnew;


const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};


bool check(int x, int y){
	if(!cont[x][y]) return false;
	int cnt = 0;
	for (int i=0; i<4; i++){
		if (cont[x+xd[i]][y+yd[i]]) cnt++;
	}
	if (cnt == 3) return true;
	else return false;
}


void add(int x, int y){
	for (int i=0; i<4; i++){
		int xx = x+xd[i], yy = y+yd[i];
		if (!cont[xx][yy]){
			cont[xx][yy]=1;
			countnew++;

			if (check(xx, yy)) add(xx, yy);
			for (int m=0; m<4; m++){
				if (check(xx+xd[m], yy+yd[m])) add(xx+xd[m], yy+yd[m]);
			}
		}
	}
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.in","r",stdin);
		freopen("1.out","w",stdout);
	#endif
	cin>>N;
	for (int i=0; i<N; i++){
		int x, y; cin>>x>>y;
		x += 1000; y += 1000;
		if (cont[x][y]) countnew--;
		else cont[x][y] = 1;
		if (check(x, y)) add(x, y);
		for (int m=0; m<4; m++){
			if (check(x+xd[m], y+yd[m])) add(x+xd[m], y+yd[m]);
		}
		cout<<countnew<<endl;
	}
	
}
