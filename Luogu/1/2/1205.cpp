#include <bits/stdc++.h>
using namespace std;

vector<long long> ans;  // ans[x] 存的是dfs(x,n)的结果
long long dfs(int x, int n) {
    if (x > n) return 0;
    if (x == n) return 1;
    if (ans[x] != 0) return ans[x];
    ans[x] = dfs(x + 1, n) + dfs(x + 2, n);
    return ans[x];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1205.in", "r", stdin);
    freopen("1205.out", "w", stdout);
#endif
    int n;
    cin >> n;
    ans.resize(n + 1);
    ans[n] = 1;
    ans[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) 
        ans[i] = ans[i + 1] + ans[i + 2];
    cout <<ans[0]<<endl;
    return 0;
}