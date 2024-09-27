#include <iostream>
using namespace std;
int x[1005];
int y[1005];
char dire[1005];

int dire_blame[1005];
int blame[1005];
int eat[1005];
int stop[1005];

int crossX[250005];
int crossY[250005];
int tail;
int tt[250005];


int loss[250005];
int win[250005];

void sort(int l, int r){
	int i = l, j = r, x = tt[(l+r)/2];
	while(i<=j){
		while(tt[i]<x)i++;
		while(tt[j]>x)j--;
		if(i<=j){
			int tmp = tt[i];
			tt[i] = tt[j];
			tt[j] = tmp;
			
			tmp = crossX[i];
			crossX[i] = crossX[j];
			crossX[j] = tmp;

			tmp = crossY[i];
			crossY[i] = crossY[j];
			crossY[j] = tmp;

			tmp = loss[i];
			loss[i] = loss[j];
			loss[j] = tmp;

			tmp = win[i];
			win[i] = win[j];
			win[j] = tmp;
			i++;
			j--;
		}
	}
	if(i<r)sort(i,r);
	if(l<j)sort(l,j);
}

void cal_blame(int x){
	int y = dire_blame[x];
	if(y){
		blame[y]++;
		cal_blame(y);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("rut.in","r",stdin);
	freopen("rutt.out","w",stdout);
#endif
	int n;
	cin>>n;
	for(int i = 1; i <= n;i++){
		cin>>dire[i]>>x[i]>>y[i];
	}



	//算交汇点和(一头牛撞到另一头牛航迹上的时间)
	for(int i = 1; i<=n;i++){
		if(dire[i]=='E'){
			for(int j = 1; j<=n;j++){
				if(dire[j]=='N'){
					int cy = y[i];
					int cx = x[j];

					int disi = cx - x[i];
					int disj = cy - y[j];
					if(disi >= 0 && disj >= 0){
						if(disi!=disj){
							
							crossX[tail] = cx;
							crossY[tail] = cy;
							if(disi>disj){
								tt[tail] = disi;
								loss[tail] = i;
								win[tail] = j;
							}
							else{         
								tt[tail] = disj;
								loss[tail] = j;
								win[tail] = i;
							}
							tail++;
						}
					}
				}
			}
		}
	}
	
	if(tail==0){
		for(int i = 0; i < n; i++){
			cout<<0<<endl;
			
	
		}
		return 0;
	}
	sort(0,tail-1);
	//simulating

	for(int i = 0; i < tail; i++){
		int t = tt[i];
		int winner = win[i];
		int losser = loss[i];
		for(int j = 1; j <= n; j++){
			if(!stop[j]){
				eat[j] = t;
			}
		}
		//check if winner managed to reach this cross
		if(dire[winner]=='N'){
			if(crossY[i]-y[winner]>eat[winner])continue;
		}else{
			if(crossX[i]-x[winner]>eat[winner])continue;
		}
		if(stop[losser])continue;
		stop[losser] = 1;
		dire_blame[losser]=winner;

	}
	

	for(int i = 1; i <= n; i++){
		cal_blame(i);
	}
	for(int i = 1; i <= n; i++){
		cout<<blame[i]<<endl;
	}
	return 0;
}