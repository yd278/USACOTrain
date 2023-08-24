#include <bits/stdc++.h>
using namespace std;
vector<int> d;
int n;
int t_max;
bool check(int k) {
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < k; i++) q.push(d[i]);
    for (int i = k; i < n; i++) {
        int h = q.top();
        q.pop();
        if (d[i] + h > t_max) return false;
        q.push(d[i] + h);
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
#endif
    cin >> n >> t_max;
    d.resize(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    int l = 1;
    int r = n;
    while (l != r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}