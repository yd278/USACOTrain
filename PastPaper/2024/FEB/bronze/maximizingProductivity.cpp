#include <bits/stdc++.h>

#include <cstddef>
using namespace std;
struct query{
	int s, v;
	int index;
	bool operator< (const query &other) const{
		return s > other.s;
	}
};
int main() {

    int n, q;
    cin >> n >> q;
    vector<int> diff(n);
    for (auto &c : diff) cin >> c;
    int t;
    for (auto &d : diff) {
        cin >> t;
        d = d - t;
    }
    sort(diff.begin(), diff.end());
    vector<query> queries(q);
    for (auto &qur : queries)
		cin >> qur.v >> qur.s;
	for(int i = 0; i < q; i++)queries[i].index = i;
	sort(queries.begin(),queries.end());
	int di = n-1;
	vector<bool> ans(q);
	for(auto &qur:queries){
		while(di >= 0&& diff[di] > qur.s)di--;
		if(n-di-1>=qur.v) ans[qur.index] = true;
	}
	for(auto a : ans){
		cout<<(a?"YES\n":"NO\n");
	}
    return 0;
}
