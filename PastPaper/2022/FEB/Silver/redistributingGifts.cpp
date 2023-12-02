#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	vector<vector<int>>wishlists(n);
	for(auto & wishlist : wishlists){
		wishlist.resize(n);
		for(auto & gift : wishlist){
			cin>>gift;
			gift--;
		}
	}
	vector<bitset<512>> reachable(n);
	
	for(int i = 0; i < n; i++){
		auto wishlist = wishlists[i];
		for(auto gift : wishlist){
			reachable[i][gift] = 1;
			if(gift == i) break;
		}
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i<n; i++ ){
			if(reachable[i][k])
				reachable[i] |= reachable[k];
		}
	}
	for(int i = 0; i < n ;i++){
		auto wishlist = wishlists[i];
		for(auto gift : wishlist){
			if(reachable[gift][i]){
				cout<<gift + 1<<endl;
				break;
			}
		}
	}
	return 0;
}
