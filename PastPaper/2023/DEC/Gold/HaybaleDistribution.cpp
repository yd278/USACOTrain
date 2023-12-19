#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct segment {
    int begin, end;  // 前闭后开
    long long p, q;
    long long dp, dq;
    double dqdp;
    bool operator<(const segment &other) const { return dqdp < other.dqdp; }
};

struct query {
    long long a, b;
    int index;
    double ab;
    bool operator<(const query &other) const { return ab < other.ab; }
};
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("HaybaleDistribution.in", "r", stdin);
//     freopen("HaybaleDistribution.out", "w", stdout);
// #endif
    int n;
    cin >> n;
    vector<int> barn(n);
    for (auto &b : barn) cin >> b;
    sort(barn.begin(), barn.end());
	barn.push_back(barn.back()+1);
    vector<segment> segs;
    segment firstSeg;
    firstSeg.begin = barn[0];
    firstSeg.end = barn[1];
    firstSeg.p = 0;
    firstSeg.dp = 1;
    segs.push_back(firstSeg);
    for (int i = 1; i < n; i++) {
        segment nxt;
        segment prev = segs.back();
        nxt.begin = barn[i];
        nxt.end = barn[i + 1];
        nxt.dp = prev.dp + 1;
        nxt.p = prev.p + prev.dp * (prev.end - prev.begin);
        segs.push_back(nxt);
    }

    segs.back().q = 0;
    segs.back().dq = 0;
    for (int i = segs.size() - 2; i >= 0; i--) {
        segment prev = segs[i + 1];
        segs[i].dq = prev.dq + 1;
        segs[i].q = prev.q + segs[i].dq * (segs[i].end - segs[i].begin);
    }
    for (int i = 0; i < segs.size(); i++) {
        segs[i].dqdp = (double)segs[i].dq / (double)segs[i].dp;
    }

    sort(segs.begin(), segs.end());

    int q;
    cin >> q;
    vector<query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].a >> queries[i].b;
        queries[i].index = i;
        queries[i].ab = (double)queries[i].a / (double)queries[i].b;
    }
	sort(queries.begin(),queries.end());
    vector<long long> ans(q);

    int qPointer = 0;
    int sPointer = 0;
	while(qPointer<q){
		while(sPointer+1< segs.size()-1 && segs[sPointer+1].dqdp < queries[qPointer].ab)sPointer++;
		long long ans1 = segs[sPointer].p * queries[qPointer].a + segs[sPointer].q * queries[qPointer].b;
		long long ans2 = segs[sPointer+1].p * queries[qPointer].a + segs[sPointer+1].q * queries[qPointer].b;
		ans[queries[qPointer].index] = min(ans1,ans2);
		qPointer++;
	}
	for(int i = 0; i < q; i++){
		cout<<ans[i]<<"\n";
	}
    return 0;
}
