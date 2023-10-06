#include <bits/stdc++.h>
using namespace std;
vector<int> lastP;
vector<int> turns;
vector<int> prime;
vector<bool> comp;
#define MAXN 5000001
int main() {
    lastP.resize(4);
    comp.resize(MAXN);
    turns.resize(MAXN);
	lastP[0] = 2;
	turns[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (!comp[i]) {
            prime.push_back(i);
			lastP[i%4] = i;
        }
        for (auto p : prime) {
            if (i * p > MAXN) break;
            comp[i * p] = true;
            if (i % p == 0) break;
        }
		turns[i] = (i - lastP[i%4]) / 2 + 1;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = MAXN;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (turns[a] / 2 < ans / 2) ans = turns[a];
        }
        if (ans & 1)
            cout << "Farmer John" << endl;
        else
            cout << "Farmer Nhoj" << endl;
    }
    return 0;
}
