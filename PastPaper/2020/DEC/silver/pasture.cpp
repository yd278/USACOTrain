#include <iostream>
#include <algorithm>
using namespace std;
int xs[2505];
int ys[2505];
int map[2505][2505];
int sum[2505][2505];
int indexX[2505];
int indexY[2505];

int revX[2505];
void qsort(int l, int r,int a[],int b[]){
	int i = l, j = r, x = a[(i+j)/2];
	while(i<=j){
		while(a[i]<x)i++;
		while(a[j]>x)j--;
		if(i<=j){
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			i++;
			j--;
		}
	}
	if(i<r)qsort(i,r,a,b);
	if(l<j)qsort(l,j,a,b);
}


int main(){

	int n;
	cin >>n;
	for(int i = 0; i < n; i++){
		cin>>xs[i]>>ys[i];
	}
	for(int i = 0; i < n; i++){
		indexX[i] = indexY[i] = i;
	}

	qsort(0,n-1,xs,indexX);
	for(int i = 0; i <n; i++){
		xs[i] = i;
	}
	qsort(0,n-1,indexX,xs);

	qsort(0,n-1,ys,indexY);
	for(int i = 0; i <n; i++){
		ys[i] = i;
	}
	qsort(0,n-1,indexY,ys);

	for(int i = 0 ; i < n ; i++){
		map[xs[i]][ys[i]] = 1;
	}
	sum[0][0] = map[0][0];
	
	for(int i = 1; i < n; i++){
		sum[0][i] = sum[0][i-1] + map[0][i];
		sum[i][0] = sum[i-1][0] + map[i][0];	
	}
	for (int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			sum[i][j] = map[i][j] + sum[i-1][j] + sum[i][j-1]-sum[i-1][j-1];
		}
	}
	
	//枚举上下边界
	long long total = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int Upper = max(ys[i],ys[j]);
			int Lower = min(ys[i],ys[j]);
			int Left = min(xs[i],xs[j]);
			int Right = max(xs[i],xs[j]);
			//左边可以当边界的点的条件： y在U和L之间，x小于L
			int leftCount = sum[Left-1][Upper] - sum[Left-1][Lower];
			
			//右边可以当边界的点的条件： y在U和L之间，x大于R
			int rightCount = sum[n-1][Upper] - sum[Right][Upper]- sum[n-1][Lower] + sum[Right][Lower];
			total += (long long) (leftCount+1) * (long long) (rightCount+1);
		}
	}
	cout<<total+1+n<<endl;
}