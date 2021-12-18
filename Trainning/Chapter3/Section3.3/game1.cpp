/*
ID: dyh2191
LANG: C++14
TASK: game1
*/
#include <cstdio>
#include <iostream>
using namespace std;
int f[100][100];

int sum[100];

//f[i][j] 表示剩下区间[i,j]时先手能得到的最高分
//若只剩一个 j==i，先手得到c[i] (sum[i+1]-sum[i])
//若剩多个,j>i，先手得到 (sum[j+1] - sum[i])-min{f[i+1][j],f[i][j-1]}

inline int min(int x, int y){
	return x>y?y:x;
}
int main(){
	int n;
#ifndef ONLINE_JUDGE
    freopen("game1.in","r",stdin);
    freopen("game1.out","w",stdout);
#endif
	scanf("%d\n",&n);
	int a;
	for(int i = 0; i < n; i++){
		scanf("%d\n",&a);
		f[i][i] = a;
		sum[i + 1] = sum[i] + a;
	}


	for(int k = 1; k < n; k++){//i 和j之间的距离
		for (int i = 0; i< n; i++){
			if(i+k<n){
				int j = i + k;
				f[i][j] = sum[j+1] - sum[i] - min(f[i+1][j],f[i][j-1]);
			}
		
		}
	}
    cout<<f[0][n-1]<<" "<<sum[n]-f[0][n-1]<<endl;
	return 0;


	
}