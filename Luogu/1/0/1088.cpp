#include <bits/stdc++.h>
using namespace std;

inline int lowbit(int x) { return x & -x; }

struct Node {
    int sum;
    Node *left;
    Node *right;
    int l, r;
};

Node *buildTree(int l, int r) {
    if (l == r) {
        Node *node = new Node();
        node->sum = 1;
        node->left = nullptr;
        node->right = nullptr;
        node->l = l;
        node->r = l;
        return node;
    }
    int mid = (l + r) / 2;
    Node *node = new Node();
    node->left = buildTree(l, mid);
    node->right = buildTree(mid + 1, r);
    node->sum = node->left->sum + node->right->sum;
    node->l = l;
    node->r = r;
    return node;
}

void del(int x, Node *root) {
    if (root->l == x && root->r == x) {
        root->sum = 0;
        return;
    }
    int mid = (root->l + root->r) / 2;
    if (x <= mid)
        del(x, root->left);
    else
        del(x, root->right);
    root->sum--;
}

int query(int x, Node *root) {
    if(root->l == root->r) return root->l;
    if(root->left->sum > x) return query(x,root->left);
    else return query(x-root->left->sum,root->right);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("1088.in", "r", stdin);
    freopen("1088.out", "w", stdout);
#endif
    // 输入部分
    int n, m;
    cin >> n >> m;
    vector<int> ori(n + 1);
    for (int i = 1; i <= n; i++) cin >> ori[i];
    vector<int> cantor(n + 1);
    // 树状数组部分
    vector<int> BIT(n + 1); // binary indexed tree
    for (int i = 1; i <= n; i++) BIT[i] = lowbit(i);

    for (int i = 1; i <= n; i++) {
        int x = ori[i] - 1;
        int sum = 0;
        while (x > 0) {
            sum += BIT[x];
            x -= lowbit(x);
        }
        cantor[i] = sum;
        x = ori[i];
        while(x <= n){
            BIT[x] --;
            x+= lowbit(x);
        }
    }

    // 进位部分
    cantor[n] += m;
    for (int i = n; i > 0 && cantor[i] >= (n - i + 1); i--) {
        cantor[i - 1] += cantor[i] / (n - i + 1);
        cantor[i] %= n - i + 1;
    }

    // 线段树部分
    Node* root = buildTree(1,n);
    for(int i = 1; i <= n; i++){
        int x = cantor[i];
        int y = query(x,root);
        cout<<y<<" ";
        del(y,root);
    }
    return 0;
}