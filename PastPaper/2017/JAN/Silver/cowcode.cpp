#include <bits/stdc++.h>
using namespace std;

long long n;
// 0 1 2 3 4 5 6 7
// 0 1 2 3 3 0 1 2
long long stepDown(long long n, long long len, long long target) {
    if (len == target) return n;
    if (n < len / 2) return stepDown(n, len / 2, target);
    if (n == len / 2) return stepDown(len / 2 - 1, len / 2, target);
    return stepDown(n - len / 2 - 1, len / 2, target);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
#endif
    string s;
    cin >> s;
    cin >> n;
    n--;
    long long len = s.length();
    while (len < n) len *= 2;
    long long t = stepDown(n, len, s.length());
    cout << s[t] << endl;
}