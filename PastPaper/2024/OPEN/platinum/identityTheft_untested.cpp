#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
struct TreeNode {
    shared_ptr<TreeNode> left, right;
    long long depth = 0;
    long long hole_depth;
    bool hole_dire;  // false:left, true:right;
    long long cnt = 0;
    shared_ptr<TreeNode> pr;
};
void update_hole(shared_ptr<TreeNode> cur) {
    while (cur->pr) {
        auto tmp = cur->hole_depth;
        auto tmpD = cur->hole_dire;
        if (!cur->left) {
            cur->hole_depth = cur->depth + 1;
            cur->hole_dire = false;
        } else if (!cur->right) {
            cur->hole_depth = cur->depth + 1;
            cur->hole_dire = true;

        } else if (cur->left->hole_depth <= cur->right->hole_depth) {
            cur->hole_depth = cur->left->hole_depth;
            cur->hole_dire = false;
        } else {
            cur->hole_depth = cur->right->hole_depth;
            cur->hole_dire = true;
        }
        if (cur->hole_depth == tmp && cur->hole_dire == tmpD) break;
        cur = cur->pr;
    }
}
shared_ptr<TreeNode> buildTree(shared_ptr<TreeNode> cur, string &s,
                               long long d) {
    if (d == s.length()) {
        cur->cnt++;
        update_hole(cur);
        return cur;
    }
    auto &p = s[d] == '0' ? cur->left : cur->right;
    if (!p) {
        p = make_shared<TreeNode>();
        p->pr = cur;
        p->depth = d + 1;
    }

    auto res = buildTree(p, s, d + 1);
    return res;
}

shared_ptr<TreeNode> process(shared_ptr<TreeNode> cur) {
    auto &p = cur->hole_dire ? cur->right : cur->left;
    shared_ptr<TreeNode> res;
    if (p) {
        res = process(p);
    } else {
        if (!cur->left && !cur->right && cur->cnt == 1) {
            ans++;
            cur->left = make_shared<TreeNode>();
            cur->left->cnt = 1;
            cur->left->depth = cur->depth + 1;
            cur->left->pr = cur;
            update_hole(cur->left);

            cur->right = make_shared<TreeNode>();
            cur->right->cnt = 1;
            cur->right->depth = cur->depth + 1;
            cur->right->pr = cur;
            update_hole(cur->right);

            res = cur->right;
            cur->cnt = 0;
        } else {
            p = make_shared<TreeNode>();
            p->cnt = 1;
            p->depth = cur->depth + 1;
            p->pr = cur;
            res = p;
            update_hole(p);
        }
    }
    return res;
}

bool cmp(shared_ptr<TreeNode> a, shared_ptr<TreeNode> b) {
    return a->depth > b->depth;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("identityTheft.in", "r", stdin);
    freopen("identityTheft.out", "w", stdout);
#endif
    int n;
    cin >> n;
    auto root = make_shared<TreeNode>();
    string s;
    vector<shared_ptr<TreeNode>> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        cows[i] = buildTree(root, s, 0);
        assert(cows[i]->depth == s.length());
    }
    sort(cows.begin(), cows.end(), cmp);

    for (auto cow : cows) {
        if (cow->cnt == 1 && cow->left == nullptr && cow->right == nullptr)
            continue;
        auto tmp = process(cow);
        cow->cnt--;
        ans += tmp->depth - cow->depth;
    }
    cout << ans << endl;
    return 0;
}