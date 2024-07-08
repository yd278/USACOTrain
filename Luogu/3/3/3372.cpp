#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    long long val;
    int bL;
    int bR;
    long long delta;
    TreeNode *pL;
    TreeNode *pR;
};
vector<long long> a;

TreeNode *buildTree(int l, int r) {
    if (l == r - 1) {
        TreeNode *t = new TreeNode{a[l], l, r, 0, nullptr, nullptr};
        return t;
    }
    TreeNode *t = new TreeNode;
    int mid = (l + r) / 2;
    t->bL = l;
    t->bR = r;
    t->pL = buildTree(l, mid);
    t->pR = buildTree(mid, r);
    t->val = t->pL->val + t->pR->val;
    return t;
}

long long query(TreeNode *root, int qL, int qR) {
    if (root->delta) {
        if (root->pL) root->pL->delta += root->delta;
        if (root->pR) root->pR->delta += root->delta;
        root->val += root->delta * (root->bR - root->bL);
        root->delta = 0;
    }
    if (qR == root->bR && qL == root->bL) return root->val;
    int mid = (root->bL + root->bR) / 2;
    if (qL >= mid) return query(root->pR, qL, qR);
    if (qR <= mid) return query(root->pL, qL, qR);
    return query(root->pL, qL, mid) + query(root->pR, mid, qR);
}

void add(TreeNode *root, int qL, int qR, long long k) {
    if (qR == root->bR && qL == root->bL) {
        root->delta += k;
        return;
    }
    root->val += (qR - qL) * k;
    int mid = (root->bL + root->bR) / 2;
    if (qL >= mid) {
        add(root->pR, qL, qR, k);
        return;
    };
    if (qR <= mid) {
        add(root->pL, qL, qR, k);
        return;
    }
    add(root->pL, qL, mid, k);
    add(root->pR, mid, qR, k);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("3372.in", "r", stdin);
    freopen("3372.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    TreeNode *root = buildTree(0, n);

    int q, l, r;
    long long k;
    for (int i = 0; i < m; i++) {
        cin >> q >> l >> r;
        if (q == 2) {
            cout << query(root, l - 1, r) << endl;
        } else {
            cin >> k;
            add(root, l - 1, r, k);
        }
    }
    return 0;
}
