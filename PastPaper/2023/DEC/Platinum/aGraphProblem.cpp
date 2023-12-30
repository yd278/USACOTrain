#include <bits/stdc++.h>
using namespace std;
#define MODN 1000000007ll
vector<long long> powers;
struct Serise {
    long long h = 0;
    int size = 0;
    Serise cat(const Serise& other) const {
        long long res = h * powers[other.size];
        if (res > MODN) res %= MODN;
        res += other.h;
        if (res > MODN) res %= MODN;
        return {res, size + other.size};
    }
};

vector<int> flag;
int getFlag(int x) {
    if (flag[x] == x)
        return x;
    else
        return flag[x] = getFlag(flag[x]);
}

struct TreeNode {
    Serise e = {0, 0};
    int u;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    Serise suffix = {0, 0};
    TreeNode* pr = nullptr;
    TreeNode* nxt = nullptr;
    Serise h = {0, 0};
};
struct hSerise {
    TreeNode* top;
    Serise h;
};

void updateH(vector<hSerise>& h, int n, TreeNode* target) {
    stack<TreeNode*> path;
    while (h[n].top != target) {
        path.push(h[n].top);
        h[n].h = h[n].h.cat(h[n].top->suffix);
        h[n].top = h[n].top->nxt;
    }
    if (!path.empty()) path.pop();
    while (!path.empty()) {
        path.top()->suffix = path.top()->suffix.cat(path.top()->nxt->suffix);
        path.top()->nxt = target;
        path.pop();
    }
}
int main() {
    // #ifndef ONLINE_JUDGE
    // 	freopen("aGraphProblem.in","r",stdin);
    // 	freopen("aGraphProblem.out","w",stdout);
    // #endif
    int n, m;
    cin >> n >> m;
    TreeNode* root = nullptr;
    powers.resize(n);
    powers[0] = 1;
    for (int i = 1; i < n; i++) {
        powers[i] = powers[i - 1] * 10;
        if (powers[i] >= MODN) powers[i] = powers[i] % MODN;
    }
    flag.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        flag[i] = i;
    }
    vector<TreeNode*> leaves(n + 1);
    for (int i = 1; i <= n; i++) {
        leaves[i] = new TreeNode();
        leaves[i]->u = i;
    }
    vector<TreeNode*> lookup(n + 1);
    for (int i = 1; i <= n; i++) {
        lookup[i] = leaves[i];
    }
    vector<hSerise> h(n + 1);
    for (int i = 1; i <= n; i++) {
        h[i].top = leaves[i];
    }
    for (int i = 1; i <= m; i++) {
        int u1, u2;
        cin >> u1 >> u2;
        int flag1 = getFlag(u1);
        int flag2 = getFlag(u2);
        if (flag1 == flag2) continue;
        auto t1 = lookup[flag1];
        auto t2 = lookup[flag2];
        TreeNode* tmp = new TreeNode;
        root = tmp;
        tmp->e = {i, 1};
        tmp->left = t1;
        tmp->right = t2;
        t1->u = u1;
        t2->u = u2;
        t1->pr = tmp;
        t2->pr = tmp;
        t1->nxt = tmp;
        t2->nxt = tmp;

        updateH(h, u1, t1);
        updateH(h, u2, t2);
        t1->suffix = tmp->e.cat(h[u2].h);
        t2->suffix = tmp->e.cat(h[u1].h);

        flag[flag2] = flag1;
        lookup[flag1] = tmp;
        root = tmp;
    }
    for (int i = 1; i <= n; i++) {
        if (h[i].top != root) {
            updateH(h, i, root);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << h[i].h.h << "\n";
    }
    return 0;
}
