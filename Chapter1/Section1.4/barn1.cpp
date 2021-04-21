/*
ID: dyh2191
LANG: C++14
TASK: barn1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int barns[201];
vector<int> gap;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("barn1.in","r",stdin);
		freopen("barn1.out","w",stdout);
	#endif
	int m, s, c;
	cin >> m >> s >> c;
	int a;
	int min = 201;
	int max = 0;
	for(int i = 0; i < c; i++){
		cin >> a;
		barns[a] = 1;
		if(min > a) min = a;
		if(max < a) max = a; 
	}
	int prev ;

	for(int i = min + 1; i <= max; i++){
		if(barns[i] ^ barns[i - 1]){
			if(!barns[i]) prev = i;
			else {
				gap.push_back(i - prev);
			}
		}
	}
	sort(gap.begin(),gap.end());
	int res = max - min + 1;
	int n = gap.size();
	for(int i = 2; i <= m; i++){
		if(n - i + 1 >= 0)
			res -= gap[n - i + 1];
		else break;
		
	}
	cout<<res<<endl;
	return 0;
}