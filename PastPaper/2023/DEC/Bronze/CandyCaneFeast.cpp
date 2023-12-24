#include <bits/stdc++.h>
using namespace std;

int main(){
	// #ifndef ONLINE_JUDGE
	// 	freopen("CandyCaneFeast.in","r",stdin);
	// 	freopen("CandyCaneFeast.out","w",stdout);
	// #endif
	int n,m;
	cin>>n>>m;

	vector<long long> cows(n);
	for(int i = 0; i < n; i++)cin>>cows[i];
	for(int i = 0; i < m; i++){
		long long cane;
		cin>>cane;
		long long bottom = 0;
		for(int c = 0; c < n; c++){
			if(cows[c]<= bottom)continue;
			if(cows[c] >= cane){
				cows[c] += cane - bottom;
				break;
			}
			long long tmp = cows[c];
			cows[c] += cows[c] - bottom;
			bottom = tmp;
		}

	}
	for(int i = 0; i < n; i++){
		cout<<cows[i]<<"\n";
	}
	return 0;
}
