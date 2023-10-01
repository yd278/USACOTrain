#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int ans[3][3] = {
    {1, 0, 1}, 
    {0, 2, 0}, 
    {1, 0, 3}
};
const int cal[3] = {3, 0, 1};
ll calcCow(ll shift, ll side) {
    if (side == 1) return 1;
    if (side == 3) return cal[shift];
    side /= 3;
    if (shift < side) return 3 * calcCow(shift, side);
    if (shift == side) return 0;
    if (shift < 2 * side) return calcCow(2 * side - shift, side);
    return calcCow(shift - 2 * side, side);
}

ll query(ll x, ll y, ll side) {
    if (x > y) swap(x, y);
    if (side == 3) return ans[x][y];
    side /= 3;
    ll shift = y - x;
    if (shift < side) {
        if (y < side) return query(x, y, side);
        if (x < side) return calcCow(shift, side);
        if (y < 2 * side)
            return calcCow(shift, side) + query(x - side, y - side, side);
        if (x < 2 * side) return calcCow(shift, side) * 2;
        return calcCow(shift, side) * 2 +
               query(x - 2 * side, y - 2 * side, side);
    }
    if (shift == side) return 0;
    if (shift < 2 * side) {
        if (y < 2 * side) return 0;
        if (x < side) return query(x, y - 2 * side, side);
        return calcCow(2 * side - shift, side);
    }
    return query(x, y - 2 * side, side);
}
ll query(ll x, ll y) {
    if (x < 0 || y < 0) return 0;
    if (x > y) swap(x, y);
    ll side = 3;
    while (side <= y) side *= 3;
    return query(x, y, side);
}

int main() {

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll d, x, y;
        cin >> d >> x >> y;
        cout << query(x + d, y + d) - query(x - 1, y - 1) << endl;
    }
    return 0;
}
