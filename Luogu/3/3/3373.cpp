#include <bits/stdc++.h>
using namespace std;

struct ModInt {
    int v;
    static int MOD;
    ModInt(long long _v = 0) {
        v = _v % MOD;
        if (v < 0) v += MOD;
    }

    ModInt& operator+=(const ModInt& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& o) {
        v = (int)(1LL * v * o.v % MOD);
        return *this;
    }

    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& m) {
        return os << m.v;
    }
};
using mint = ModInt;
int mint::MOD = 1e9 + 7;
struct TreeNode {
    mint sum;
    mint add_tag;
    mint mul_tag;
};
class SegmentTree {
    int n;
    vector<TreeNode> tree;
    void push_up(int node) {
        tree[node].sum = tree[node << 1].sum + tree[node << 1 | 1].sum;
    }

    // 只算自己，不往下传
    void apply(int node, int nL, int nR, mint mul, mint add) {
        tree[node].sum = tree[node].sum * mul + add * (nR - nL + 1);
        tree[node].mul_tag = tree[node].mul_tag * mul;
        tree[node].add_tag = tree[node].add_tag * mul + add;
    }
    void push_down(int node, int nL, int nR) {
        int mid = (nL + nR) >> 1;
        apply(node << 1, nL, mid, tree[node].mul_tag, tree[node].add_tag);
        apply(node << 1 | 1, mid + 1, nR, tree[node].mul_tag,
              tree[node].add_tag);
        tree[node].mul_tag = 1;
        tree[node].add_tag = 0;
    }

    void update(int node, int nL, int nR, int qL, int qR, mint mul, mint add) {
        if (qL <= nL && nR <= qR) {
            apply(node, nL, nR, mul, add);
            return;
        }
        push_down(node, nL, nR);
        int mid = (nL + nR) >> 1;
        if (qL <= mid) update(node << 1, nL, mid, qL, qR, mul, add);
        if (qR > mid) update(node << 1 | 1, mid + 1, nR, qL, qR, mul, add);
        push_up(node);
    }

    void build(const vector<int>& data, int node, int nL, int nR) {
        if (nL == nR) {
            tree[node] = {data[nL - 1], 0, 1};
            return;
        }
        int mid = (nL + nR) >> 1;
        build(data, node << 1, nL, mid);
        build(data, node << 1 | 1, mid + 1, nR);
        push_up(node);
        tree[node].add_tag = 0;
        tree[node].mul_tag = 1;
    }

    mint query(int node, int nL, int nR, int qL, int qR) {
        if (qL <= nL && qR >= nR) return tree[node].sum;
        push_down(node, nL, nR);
        mint res = 0;
        int mid = (nL + nR) >> 1;
        if (qL <= mid) res += query(node << 1, nL, mid, qL, qR);
        if (qR > mid) res += query(node << 1 | 1, mid + 1, nR, qL, qR);
        return res;
    }

   public:
    SegmentTree(int size) : n(size) {
        tree.resize(n << 2, {0, 0, 1});
        update(1, 1, n, 1, n, 1, 1);
    }
    SegmentTree(vector<int> data) : n(data.size()) {
        if (n == 0) return;
        tree.resize(n << 2);
        build(data, 1, 1, n);
    }
    void range_mul(int qL, int qR, mint k) { update(1, 1, n, qL, qR, k, 0); }
    void range_add(int qL, int qR, mint k) { update(1, 1, n, qL, qR, 1, k); }
    mint range_query(int qL, int qR) { return query(1, 1, n, qL, qR); }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("3373.in", "r", stdin);
    freopen("3373.out", "w", stdout);
#endif
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> data(n);
    for (auto& d : data) cin >> d;
    ModInt::MOD = m;
    int o, x, y, k;
    SegmentTree tree(data);
    for (int i = 0; i < q; i++) {
        cin >> o >> x >> y;
        if (o == 1) {
            cin >> k;
            tree.range_mul(x, y, k);
        }
        if (o == 2) {
            cin >> k;
            tree.range_add(x, y, k);
        }
        if (o == 3) {
            cout << tree.range_query(x, y) << endl;
        }
    }

    return 0;
}
