#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct event {
    ll x, y, t;
    bool operator<(const event &other) const { return t < other.t; }
    bool unreachable(const event &other) const {
        return (t- other.t) * (t-other.t) < (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
    }
};

int main() {

    int g, n;
    cin >> g >> n;
    vector<event> gardens(g);
    for (auto &gar : gardens) {
        cin >> gar.x >> gar.y >> gar.t;
    }
    sort(gardens.begin(), gardens.end());
    vector<event> cows(n);
    for (auto &cow : cows) {
        cin >> cow.x >> cow.y >> cow.t;
    }
    sort(cows.begin(), cows.end());
    int succ = 0;
    int ans = 0;
    int iter = 0;
    for (; cows[iter].t < gardens.front().t; iter++) {
        if(cows[iter].unreachable(gardens.front()))ans++;
    }
    for (int i = 1; i < g; i++) {
        while (cows[iter].t < gardens[i].t) {
			if(cows[iter].unreachable(gardens[i]) || cows[iter].unreachable(gardens[i-1])) ans++;
			iter++;
        }
    }
	for(; iter<n; iter++){
		if(cows[iter].unreachable(gardens.back()))ans++;
	}
	cout<<ans<<endl;
    return 0;
}
