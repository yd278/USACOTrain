#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll n, ll m, ll k, ll x) {  // 不能还上
    while (k > 0) {
        ll y = n / x;
        ll d;
        if (y <= m) {
            d = (n - 1) / m + 1;
            if (d > k)
                return true;
            else
                return false;
        }
        d = n / y - x + 1;

        if(d > k){
            if(k*y >= n) return false;
            else return true;
        }
        k-=d;
        n-= d*y;
        if(n<=0)return false;
    }
    return true;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
#endif
    ll n, m, k;
    cin >> n >> k >> m;

    ll upper = n;
    ll lower = 1;

    // lowerbound -1
    while (upper != lower) {
        ll mid = (upper + lower) >> 1;
        if (check(n, m, k, mid))
            upper = mid;
        else
            lower = mid + 1;
    }
    cout << lower - 1;

    return 0;
}
