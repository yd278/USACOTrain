#include <bits/stdc++.h>
using namespace std;

void process() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (auto& x : a) {
        cin >> x;
        sum += x;
    }
    long long bessie = 0;
    for (int i = 0; i < n / 2 + 1; i++) {
        bessie += a[i];
    }
    long long minB = bessie;

    for (int i = n / 2 + 1; i < n; i++) {
        bessie += a[i];
        bessie -= a[i - n / 2 - 1];
        if (bessie < minB) minB = bessie;
    }
    cout << minB << " " << sum - minB << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("cakeGame.in", "r", stdin);
    freopen("cakeGame.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        process();
    }

    return 0;
}
