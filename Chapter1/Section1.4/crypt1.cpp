/*
ID: dyh2191
LANG: C++14
TASK: crypt1
*/

#include <iostream>
#include <vector>
using namespace  std;
vector<int> digits;
int used[10];
int check(int x){
	while(x){
		if(!used[x % 10]) return false;
		x /= 10;
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("crypt1.in","r",stdin);
		freopen("crypt1.out","w",stdout);
	#endif
	int cnt = 0;
	int n,tmp;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>tmp;
		used[tmp] = 1;
		digits.push_back(tmp);
	}
	for(int a : digits){
		for(int b : digits){
			for(int c : digits){
				int abc = a * 100 + b * 10 + c;
				for(int d : digits){
					int part1 = abc * d;
					if(part1 > 999) continue;
					if(!check(part1)) continue;
					for(int e : digits){
						int part2 = abc * e;
						if(part2 > 999) continue;
						if(check(part2)){
							int product = part1 + 10 * part2;
							if(product < 9999 && check(product)) cnt++; 
						}
					}
				}
			}
		}
	}

	cout<<cnt<<endl;
	return 0;
	
}