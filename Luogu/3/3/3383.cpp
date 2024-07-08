#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100000001

bitset<MAXSIZE> not_prime;
vector<int> prime;
int main() {
#ifndef ONLINE_JUDGE
    freopen("3383.in", "r", stdin);
    freopen("3383.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prime.reserve(5761457);
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            prime.push_back(i);
        }
        for (auto p : prime) {
            if (i * p > n) break;
            not_prime[i * p] = 1;
            if (i % p == 0) break;
        }
    }
    int k;
    for (int i = 0; i < q; i++) {
        cin >> k;
        cout << prime[k-1] << "\n";
    }

    return 0;
}
