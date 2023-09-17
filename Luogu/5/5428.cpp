#include <bits/stdc++.h>
using namespace std;

// 计算几何部分
struct Point {
    long long x, y;
    int segIndex;
    bool operator<(const Point &other) const {
        if (x < other.x) return true;
        if (x == other.x && y < other.y) return true;
        return false;
    }
};

struct Seg {
    Point p, q;
};

// 判断相交
bool boundingBox(Seg a, Seg b) {
    if (max(a.p.x, a.q.x) < min(b.p.x, b.q.x)) return false;
    if (max(b.p.x, b.q.x) < min(a.p.x, a.q.x)) return false;
    if (max(a.p.y, a.q.y) < min(b.p.y, b.q.y)) return false;
    if (max(b.p.y, b.q.y) < min(a.p.y, a.q.y)) return false;
    return true;
}
int signCross(Point a, Point b) {  // 用点来表示向量
    long long res = a.x * b.y - a.y * b.x;
    if (res == 0) return 0;
    if (res > 0) return 1;
    return -1;
}
bool cis(Point o, Point a, Point b, Point c) {
    Point OA;
    OA.x = a.x - o.x;
    OA.y = a.y - o.y;

    Point OB;
    OB.x = b.x - o.x;
    OB.y = b.y - o.y;

    Point OC;
    OC.x = c.x - o.x;
    OC.y = c.y - o.y;

    int AB = signCross(OA, OB);
    int BC = signCross(OB, OC);
    return (AB * BC) >= 0;
}
bool intersect(Seg a, Seg b) {
    if (!boundingBox(a, b)) return false;
    if (cis(a.p, b.p, a.q, b.q) && cis(b.p, a.p, b.q, a.q)) return true;
    return false;
}
vector<Point> points;
vector<Seg> segs;
// 扫描线位置参数
double now;
bool segComp(Seg a, Seg b) {  // return true if 在x=now时 a在b下方
    double aLift = a.p.y - a.q.y;
    double aSpan = a.p.x - a.q.x;
    double aDist = now - a.q.x;
    double aHight = aSpan == 0 ? a.p.y : aDist / aSpan * aLift + a.q.y;

    double bLift = b.p.y - b.q.y;
    double bSpan = b.p.x - b.q.x;
    double bDist = now - b.q.x;
    double bHight = bSpan == 0 ? b.p.y : bDist / bSpan * bLift + b.q.y;
    return aHight < bHight;
}
// splay部分
struct TreeNode {
    int index = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode *parent = nullptr;
};
TreeNode *root;
void leftRotate(TreeNode *x) {
    auto y = x->right;
    auto z = x->parent;

    if (z) {
        if (x == z->left)
            z->left = y;
        else
            z->right = y;
    }
    y->parent = z;

    x->right = y->left;
    if (y->left) y->left->parent = x;

    y->left = x;
    x->parent = y;
}

void rightRotate(TreeNode *x) {
    auto y = x->left;
    auto z = x->parent;

    if (z) {
        if (x == z->left)
            z->left = y;
        else
            z->right = y;
    }
    y->parent = z;

    x->left = y->right;
    if (y->right) y->right->parent = x;

    y->right = x;
    x->parent = y;
}

void splay(TreeNode *x) {
    if (x == root) return;
    while (x->parent) {
        auto p = x->parent;
        auto g = p->parent;
        if(!g){
            if(p->left==x){
                rightRotate(p);
            }else{
                leftRotate(p);
            }
            break;
        }
        if (g->left == p) {
            if (p->left == x) {
                rightRotate(g);
                rightRotate(p);
            } else {
                leftRotate(p);
                rightRotate(g);
            }
        } else {
            if (p->right == x) {
                leftRotate(g);
                leftRotate(p);
            } else {
                rightRotate(p);
                leftRotate(g);
            }
        }
    }
    root = x;
}
TreeNode *insert(int index) {
    if (!root) {
        root = new TreeNode;
        root->index = index;

        return root;
    }
    auto cur = root;
    while (cur) {
        if (segComp(segs[index], segs[cur->index])) {
            if (cur->left)
                cur = cur->left;
            else {
                cur->left = new TreeNode;
                cur->left->parent = cur;

                cur = cur->left;
                cur->index = index;
                break;
            }
        } else {
            if (cur->right)
                cur = cur->right;
            else {
                cur->right = new TreeNode;
                cur->right->parent = cur;

                cur = cur->right;
                cur->index = index;
                break;
            }
        }
    }
    splay(cur);
    return root;
}

TreeNode *pred() {
    if (!root) return nullptr;
    auto cur = root->left;
    if (!cur) return nullptr;
    while (cur->right) {
        cur = cur->right;
    }
    return cur;
}

TreeNode *succ() {
    if (!root) return nullptr;
    auto cur = root->right;
    if (!cur) return nullptr;
    while (cur->left) {
        cur = cur->left;
    }
    return cur;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("5428.in", "r", stdin);
    freopen("5428.out", "w", stdout);
#endif
    int n;
    cin >> n;
    segs.resize(n + 1);
    points.resize(n * 2);
    for (int i = 0; i < n; i++) {
        Point p;
        Point q;
        cin >> p.x >> p.y;
        p.segIndex = i + 1;
        cin >> q.x >> q.y;
        q.segIndex = i + 1;
        points[i * 2] = p;
        points[i * 2 + 1] = q;
        segs[i + 1].p = p;
        segs[i + 1].q = q;
    }

    sort(points.begin(), points.end());
    vector<TreeNode *> position(n + 1);
    vector<bool> inSet(n + 1);
    // 扫描
    int s1, s2;
    for (int i = 0; i < n * 2; i++) {
        now = points[i].x;
        int segIndex = points[i].segIndex;
        if (inSet[segIndex]) {
            if(position[segIndex]->index!=segIndex)cout<<segIndex<<" "<<position[segIndex]->index<<endl;
            splay(position[segIndex]);
            auto p = pred();
            auto s = succ();
            if (p && s) {
                int pre = p->index;
                int suc = s->index;
                if (intersect(segs[pre], segs[suc])) {
                    s1 = pre;
                    s2 = suc;
                    break;
                }
            }
            //删除对应节点
            if(!p){
                root = position[segIndex]->right;
                if(root) root->parent = nullptr;
                delete(position[segIndex]);
                position[segIndex] = nullptr;
            }else if(!s){
                root = position[segIndex]->left;
                if(root) root->parent = nullptr;
                delete(position[segIndex]);
                position[segIndex] = nullptr;
            
            }else{
                
                auto rightRoot = root->right;
                root = root->left;
                delete(root->parent);
                root->parent = nullptr;
                splay(p);
                p->right = rightRoot;
                rightRoot->parent = root;
                position[segIndex] = nullptr;
            }
            inSet[segIndex] = false;

        } else {
            position[segIndex] = insert(points[i].segIndex);
            auto p = pred();
            if (p) {
                int pre = p->index;
                if (intersect(segs[pre], segs[segIndex])) {
                    s1 = pre;
                    s2 = segIndex;
                    break;
                }
            }
            auto s = succ();
            if (s) {
                int suc = s->index;
                if (intersect(segs[suc], segs[segIndex])) {
                    s1 = suc;
                    s2 = segIndex;
                    break;
                }
            }
            inSet[segIndex] = true;
        }
    }
    // 后面就简单了
    if (s1 > s2) swap(s1, s2);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == s2 || i == s1) continue;
        if (intersect(segs[i], segs[s2])) cnt++;
    }
    if (cnt) {
        cout << s2 << endl;
    } else {
        cout << s1 << endl;
    }
    return 0;
}