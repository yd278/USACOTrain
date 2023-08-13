#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    int bL;
    int bR;
    TreeNode *pL;
    TreeNode *pR;
};
vector<int> a;

TreeNode *buildTree(int l, int r) {
    if (l == r - 1) {
        TreeNode *t = new TreeNode{a[l], l, r, nullptr, nullptr};
        return t;
    }
    TreeNode *t = new TreeNode;
    int mid = (l + r) / 2;
    t->bL = l;
    t->bR = r;
    t->pL = buildTree(l, mid);
    t->pR = buildTree(mid, r);
    t->val = min(t->pL->val, t->pR->val);
    return t;
}

int query(TreeNode *root, int qL, int qR) {
    if (qR == root->bR && qL == root->bL) return root->val;
    int mid = (root->bL + root->bR) / 2;
    if (qL >= mid) return query(root->pR, qL, qR);
    if (qR <= mid) return query(root->pL, qL, qR);
    return min(query(root->pL, qL, mid), query(root->pR, mid, qR));
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("1816.in","r",stdin);
        freopen("1816.out","w",stdout);
    #endif
    int m,n;
    cin>>m>>n;
    a.resize(m);
    for(int i = 0; i < m; i++){
        cin>>a[i];
    }
    TreeNode *root = buildTree(0,m);
    int a,b;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        cout<<query(root,a-1, b)<<" ";
    }
    return 0;
}
