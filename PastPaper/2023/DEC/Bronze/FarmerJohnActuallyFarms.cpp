#include <bits/stdc++.h>
using namespace std;
struct Line {
    long long h;
    long long a;
    int rank;
    bool operator<(const Line &other) const { return rank > other.rank; }
};
#define MAXN 200000

vector<Line> lines;
void process(){
int n;
        cin >> n;
        lines.resize(n);
        for (auto &l : lines) cin >> l.h;
        for (auto &l : lines) cin >> l.a;
        for (auto &l : lines) cin >> l.rank;
        sort(lines.begin(), lines.end());
        long long upperBound = INTMAX_MAX; 
        long long lowerBound = 0ll;
		//[lowerBound, upperBound]
        for (int i = 0; i < n - 1; i++) {
            auto const &cur = lines[i];
            auto const &nxt = lines[i + 1];
			if(cur.h < nxt.h){
				if(cur.a > nxt.a){
					auto dh = nxt.h - cur.h;
					auto da = cur.a - nxt.a;
					auto newBound = dh/da;
					if(dh %da ==0) newBound -= 1;
					upperBound = min(upperBound, newBound);
				}
			}
			else{ //cur.h>= nxt.h
				if(cur.a>=nxt.a){
					cout<<"-1\n";
					return;
				}
				else{
					auto dh = cur.h - nxt.h;
					auto da = nxt.a - cur.a;
					auto newBound = dh/da;
					lowerBound = max(lowerBound, newBound+1); 
				}
			}
			if(upperBound<lowerBound){
				cout<<"-1\n";
				return;
			}
        }
		cout<<lowerBound<<"\n";

}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("FarmerJohnActuallyFarms.in", "r", stdin);
//     freopen("FarmerJohnActuallyFarms.out", "w", stdout);
// #endif
    int T;
    cin >> T;
    lines.reserve(MAXN);
    while (T--) {
        process();
    }
    return 0;
}
