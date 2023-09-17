#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> prev(6);
    string s;
    cin >> s;
    int n = s.length();
    s = "1" + s;
    vector<long long> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'b') prev[0] = i;
        if (s[i] == 'e') prev[5] = prev[4], prev[1] = prev[0];
        if (s[i] == 's') prev[3] = prev[2], prev[2] = prev[1];
        if (s[i] == 'i') prev[4] = prev[3];
        if(prev[5])
            dp[i] = dp[prev[5] - 1] + prev[5];
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dp[i];
    }
    cout << sum << endl;
    return 0;
}