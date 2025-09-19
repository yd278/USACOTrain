#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll mid, vector<ll>& a, vector<ll>& b, vector<ll>& c, int n, ll tC,
           ll tM) {
    double upper = min(tC - 1, mid);
    double lower = max(0LL, mid - (tM - 1));
    for (int i = 0; i < n; i++) {
        double k = c[i] - a[i] * tC - b[i] * tM + b[i] * mid;
        if (b[i] == a[i] && k < 0) return false;
        if (b[i] > a[i]) upper = min(upper, k / (b[i] - a[i]));
        if (a[i] > b[i]) lower = max(lower, k / (b[i] - a[i]));
    }
    return floor(upper) >= ceil(lower);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll tC, tM;
        cin >> n >> tC >> tM;
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }

        ll l = 0;
        ll r = tC + tM - 2;
        while (l != r) {
            ll mid = (l + r) / 2;
            if (check(mid, a, b, c, n, tC, tM))
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
