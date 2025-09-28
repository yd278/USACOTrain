#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point {
    ll x;
    ll y;
    double s;
    void computeS(ll mid) { s = (y - mid) / (double)x; }
    bool operator<(const Point& other) const { return s < other.s; }
};

bool check(ll mid, vector<ll>& s, vector<Point>& r, vector<ll> l, ll x1,
           int n) {
    for (auto& p : r) {
        p.computeS(mid);
    }
    sort(r.begin(), r.end());
    for (int i = 0; i < n; i++) {
        if (r[i].y - r[i].x * s[i] < mid) return false;
    }
    for (int i = s.size() - 1; i >= n; i--) {
        int j = (n * 2 - 1) - (s.size() - 1 - i);
        if (l[j] - s[i] * x1 < mid) return false;
    }
    return true;
}

ll binarySearch(ll low, ll high, vector<ll>& s, vector<Point>& r, vector<ll> l,
                ll x1, int n) {
    while (high > low) {
        ll mid = (low + high) / 2;
        if (check(mid, s, r, l, x1, n)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    if (check(high, s, r, l, x1, n)) return high;
    return low;
}
void process() {
    int n;
    ll x1;
    cin >> n >> x1;
    vector<Point> bottomRight(n);
    vector<Point> topRight(n);
    vector<ll> leftSide(2 * n);
    for (int i = 0; i < n; i++) {
        long long y1, y2, x2;
        cin >> y1 >> y2 >> x2;
        leftSide[i * 2] = y1;
        leftSide[i * 2 + 1] = y2;
        bottomRight[i] = {x2, y1, 0};
        topRight[i] = {x2, -y2, 0};  // reversed
    }
    sort(leftSide.begin(), leftSide.end());
    vector<ll> sPos;
    sPos.reserve(n * 4);
    vector<ll> sNeg;
    sNeg.reserve(n * 4);

    for (int i = 0; i < n * 4; i++) {
        ll s;
        cin >> s;
        if (s > 0) {
            sPos.push_back(s);
        } else {
            sNeg.push_back(-s);
        }
    }
    if (sPos.size() < n || sNeg.size() < n) {
        cout << -1 << endl;
        return;
    }

    sort(sPos.begin(), sPos.end());
    sort(sNeg.begin(), sNeg.end());

    ll low = binarySearch(INTMAX_MIN / 2, leftSide[0], sPos, bottomRight,
                          leftSide, x1, n);
    reverse(leftSide.begin(), leftSide.end());
    for (auto& l : leftSide) l = -l;
    ll high = -binarySearch(INTMAX_MIN / 2, leftSide[0], sNeg, topRight,
                            leftSide, x1, n);
    if (high > low)
        cout << high - low << endl;
    else
        cout << -1 << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        process();
    }
    return 0;
}
