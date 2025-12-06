#include <bits/stdc++.h>
using namespace std;

void process() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    int max = 0;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > max) max = a;
        cnt[a]++;
    }
    int ans = 1;
    for (int i = max - 1; i > 0; i--) {
        if (cnt[i] >= 2) ans += 2;
    }
    cout << ans << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("MoreCowPhotos.in", "r", stdin);
    freopen("MoreCowPhotos.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) process();
    return 0;
}
