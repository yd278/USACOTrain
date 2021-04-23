/*
ID: dyh2191
LANG: C++14
TASK: sort3
*/

#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int b[1001];
int cnt[4][4];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("sort3.in","r",stdin);
		freopen("sort3.out","w",stdout);
	#endif
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b,b+n);
	for(int i = 0; i < n; i++){
		cnt[a[i]][b[i]] ++;
	}
	int ans = 0;
	int res = 0;

	ans += min(cnt[1][2],cnt[2][1]);
	ans += min(cnt[2][3],cnt[3][2]);
	ans += min(cnt[1][3],cnt[3][1]);

	res += abs(cnt[1][2] - cnt[2][1]);
	res += abs(cnt[1][3] - cnt[3][1]);
	res += abs(cnt[2][3] - cnt[3][2]);
	ans += res / 3 * 2;
	cout<<ans<<endl;
	return 0;
}