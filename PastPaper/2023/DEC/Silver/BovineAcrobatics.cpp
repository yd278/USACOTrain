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
    vector<int> based(n);
    long long ans = 0;
    int top = 0;
    while (m && top < n) {
        if (cows[top].a > m) {
            cows[top].a -= m;
            based[top] = m;
            ans += m;
            m = 0;
        } else {
            based[top] = cows[top].a;
            ans += cows[top].a;
            m -= cows[top].a;
            cows[top].a = 0;
            top++;
        }
    }
    int filling = 0;
    for (; top < n; top++) {
        while (cows[top].a) {
            if (cows[top].w - cows[filling].w < k) break;
            int amount = min(cows[top].a, based[filling]);
            based[filling] -= amount;
            based[top] += amount;
            cows[top].a -= amount;
            ans += amount;
            if (based[filling] == 0) filling++;
        }
    }
    cout << ans << "\n";
    return 0;
}
