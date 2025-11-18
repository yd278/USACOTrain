#include <bits/stdc++.h>

using namespace std;
struct Restriction {
    int l, r, t;
    const bool operator<(const Restriction& other) const { return r < other.r; }
};
inline int lowbit(int x) { return x & (-x); }
struct BIT {
    BIT(int n) {
        size = n;
        a = vector<int>(n + 1);
        binary_indexed_tree = vector<int>(n + 1);
    }
    int size;
    vector<int> binary_indexed_tree;
    vector<int> a;
    int prf_sum(int i) {
        int sum = 0;
        while (i) {
            sum += binary_indexed_tree[i];
            i -= lowbit(i);
        }
        return sum;
    }
    int at(int i) { return a[i]; }
    void add(int i, int x) {
        a[i] += x;
        while (i <= size) {
            binary_indexed_tree[i] += x;
            i += lowbit(i);
        }
    }
    int sum(int l, int r) { return prf_sum(r) - prf_sum(l - 1); }
};

void process() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (auto& v : x) cin >> v;
    sort(x.begin(), x.end());
    vector<Restriction> restriction(k);
    int l, r;
    for (auto& res : restriction) {
        cin >> l >> r;
        res.l = distance(x.begin(), lower_bound(x.begin(), x.end(), l)) + 1;
        res.r = distance(x.begin(), upper_bound(x.begin(), x.end(), r));
        cin >> res.t;
    }
    BIT bit(n);
    sort(restriction.begin(), restriction.end());
    for (auto res : restriction) {
        int cur = bit.sum(res.l, res.r);
        int ptr = res.r;
        while (cur < res.t) {
            if (bit.at(ptr) == 0) {
                bit.add(ptr, 1);
                cur++;
            }
            ptr--;
        }
    }
    int total = bit.prf_sum(n);
    cout << n - total << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("Deforestation.in", "r", stdin);
    freopen("Deforestation.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}
