#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("CycleCorrespondence.in", "r", stdin);
    freopen("CycleCorrespondence.out", "w", stdout);
#endif
    bitset<500000> s;
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
		cin >> a[i];
		a[i]--;
		s.set(a[i]);
	}
    for (int i = 0; i < k; i++){
		 cin >> b[i];
		 b[i]--;
		 s.set(b[i]);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!s[i]) ans++;
	}

	vector<int>index(n,-1);
	for(int i = 0; i < k; i++){
		index[a[i]] = i;
	}
	vector<int> cnt(n);
	for(int i = 0; i < k; i++){
		if(index[b[i]]==-1)continue;
		int d = index[b[i]] - i;
		if(d<0) d+=k;
		cnt[d]++;
	}
	int sol = *max_element(cnt.begin(),cnt.end());
	reverse(b.begin(),b.end());
	fill(cnt.begin(),cnt.end(),0);

	for(int i = 0; i < k; i++){
		if(index[b[i]]==-1)continue;
		int d = index[b[i]] - i;
		if(d<0) d+=k;
		cnt[d]++;
	}
	sol = max(sol,*max_element(cnt.begin(),cnt.end()) );
	cout<<ans+sol<<"\n";
	return 0;

	
}