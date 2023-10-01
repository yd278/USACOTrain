#include <bits/stdc++.h>
using namespace std;
long long getsum(int i, int j, vector<long long> &sum) {  // [i , j] 1<= i <= maxa
    if (j >= sum.size()) return sum.back() - sum[i - 1];
    return sum[j] - sum[i - 1];
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    int maxa = 0;
    for (auto &x : a) {
        cin >> x;
        if (x > maxa) maxa = x;
    }
    vector<long long> bin(maxa + 1);
    for (auto x : a) bin[x]++;
    vector<long long> sum(maxa + 1);  // [0,i]
    sum[0] = bin[0];
    for (int i = 1; i <= maxa; i++) {
        sum[i] = sum[i - 1] + bin[i];
    }
    long long ans = 0;
    for (int s = 1; s <= maxa; s++) {
        vector<long long> seg(maxa / s + 1);
        for (auto i = 1; i <= maxa / s; i++) {
            seg[i] = getsum(i * s, i * s + s - 1, sum);
        }
        int oddcnt = 0;
        for (auto x : seg) oddcnt += x % 2;
        if (oddcnt == 1 && seg[1] % 2) ans += seg[1];
        if (oddcnt == 2) {
            for (auto i = 2; i <= maxa / s; i++) {
                if (seg[i] % 2 && seg[i - 1] % 2) {
                    ans += seg[i];
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}