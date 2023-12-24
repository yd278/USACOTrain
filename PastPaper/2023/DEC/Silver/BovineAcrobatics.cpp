#include <bits/stdc++.h>
using namespace std;
struct Cow {
    int w;
    int a;
    int next;
    bool operator<(const Cow &other) const { return w < other.w; }
};
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("BovineAcrobatics.in", "r", stdin);
//     freopen("BovineAcrobatics.out", "w", stdout);
// #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<Cow> cows(n);
    for (auto &c : cows) {
        cin >> c.w >> c.a;
    }
    sort(cows.begin(), cows.end());

    int nxt = 0;
    for (int now = 0; now < n; now++) {
        while (nxt != n && cows[nxt].w < cows[now].w + k) nxt++;
        cows[now].next = nxt;
    }

    long long ans = 0;
    vector<int> based(n);
    int smallest = 0;
    while (m && smallest < n) {
        if (cows[smallest].a > m) {
			cows[smallest].a -= m;
            based[smallest] = m;
            ans += m;
            m = 0;
        } else {
            based[smallest] = cows[smallest].a;
            m -= cows[smallest].a;
			ans+= cows[smallest].a;
			cows[smallest].a=0;
			smallest++;
        }
    }

	for(int now = 0; now < n; now++){
		while(based[now]){
			
			if(cows[now].next < smallest)cows[now].next =smallest;
			while(cows[now].next<n &&cows[cows[now].next].a==0)cows[now].next++;
			int next = cows[now].next;
			if(next >= n){
				cout<<ans<<"\n";
				return 0;
			}
			int amount = min(based[now],cows[next].a);
			based[now]-=amount;
			based[next]+= amount;
			cows[next].a -= amount;
			ans+= amount;
            smallest = next;
			while(smallest<n && cows[smallest].a==0)smallest++;
            

		}
	}
	cout<<ans<<"\n";
    return 0;
}
