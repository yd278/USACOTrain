#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    int m;
    cin >> n >> m;
    vector<char> dire(n);
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> dire[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pairs;
    for (int i = 0; i < n - 1; i++) {
        if (dire[i] == 'R' && dire[i + 1] == 'L') pairs.push_back(i);
    }
    if (dire[n - 1] == 'R' && dire[0] == 'L') pairs.push_back(n - 1);
	if(pairs.empty()){
		long long sum = 0;
		for(auto &x : a) sum += x;
		cout<<sum<<"\n";
		return 0;
	}
	long long ans = 0;
	for(int l : pairs){
		long long sum = 0;
		for(int i = (l - 1 + n) % n; dire[i]=='R';i = (i+n-1)%n){
			sum += a[i];
		}
		ans += a[l];
		ans += max(sum-m,0ll);
		sum = 0;
		for(int i = (l + 2 ) %n; dire[i] =='L'; i = (i+1)%n){
			sum += a[i];
		}
		ans += a[(l+1)%n];
		ans += max(sum-m,0ll);
	}
	cout<<ans<<"\n";
	return 0;
}
