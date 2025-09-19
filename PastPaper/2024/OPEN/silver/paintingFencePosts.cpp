#include <bits/stdc++.h>

using namespace std;
struct Seg;
struct Post {
    int x, y;
    int index;
    long long pos;
    Seg* hori_edge;
    Seg* vert_edge;
};

struct Seg {
    Post* first;
    Post* second;
    long long len;
    bool dire;  // true: start-first, end:second
    bool hori;  // true: y=y; false x=x
    Post* getStart() { return dire ? first : second; }
    Post* getEnd() { return dire ? second : first; }

    int check(int x, int y) {
        return hori ? check_hori(x, y) : check_vert(x, y);
    }

    int check_hori(int x, int y) {
        if (y < first->y) return -1;
        if (y > first->y) return 1;
        if (x < first->x) return -1;
        if (x > second->x) return 1;

        return 0;
    }
    int check_vert(int x, int y) {
        if (x < first->x) return -1;
        if (x > first->x) return 1;
        if (y < first->y) return -1;
        if (y > second->y) return 1;
        return 0;
    }
    long long get_dist(int x, int y) {
        auto start = getStart();
        return hori ? abs(x - start->x) + start->pos
                    : abs(y - start->y) + start->pos;
    }
};
bool hori_cmp(const Post* a, const Post* b) {
    if (a->y < b->y) return true;
    if (a->y == b->y && a->x < b->x) return true;
    return false;
}
bool veri_cmp(const Post* a, const Post* b) {
    if (a->x < b->x) return true;
    if (a->x == b->x && a->y < b->y) return true;
    return false;
}

Seg* find_seg(vector<Seg>& hori, vector<Seg>& vert, int x, int y) {
    int l = 0;
    int r = hori.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int res = hori[mid].check(x, y);
        if (res == 1) {
            l = mid + 1;
        } else if (res == -1) {
            r = mid - 1;
        } else {
            return &hori[mid];
        }
    }
    l = 0;
    r = vert.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int res = vert[mid].check(x, y);
        if (res == 1) {
            l = mid + 1;
        } else if (res == -1) {
            r = mid - 1;
        } else {
            return &vert[mid];
        }
    }
    return nullptr;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("paintingFencePosts.in", "r", stdin);
    freopen("paintingFencePosts.out", "w", stdout);
#endif
    int n, p;
    cin >> n >> p;
    vector<Post*> posts(p);
    vector<int> rank(p);
    vector<int> ans(p);
    for (int i = 0; i < p; i++) {
        posts[i] = new Post;
        cin >> posts[i]->x >> posts[i]->y;
        posts[i]->index = i;
    }
    // Construct all horizontal edges
    sort(posts.begin(), posts.end(), hori_cmp);
    vector<Seg> hori(p / 2);
    int top = 0;
    for (auto& seg : hori) {
        seg.first = posts[top++];
        seg.second = posts[top++];
        seg.len = seg.second->x - seg.first->x;
        seg.first->hori_edge = &seg;
        seg.second->hori_edge = &seg;
        seg.hori = true;
    }

    // Construct all vertical edges
    sort(posts.begin(), posts.end(), veri_cmp);
    vector<Seg> vert(p / 2);
    top = 0;
    for (auto& seg : vert) {
        seg.first = posts[top++];
        seg.second = posts[top++];
        seg.len = seg.second->y - seg.first->y;
        seg.first->vert_edge = &seg;
        seg.second->vert_edge = &seg;
        seg.hori = false;
    }

    auto current = posts[0];
    vector<int> order;
    order.reserve(p);
    long long total_len = 0;
    for (int i = 0; i < p / 2; i++) {
        order.push_back(current->index);
        current->pos = total_len;
        auto edge = current->hori_edge;
        total_len += edge->len;
        edge->dire = (edge->first == current);
        current = edge->getEnd();

        order.push_back(current->index);
        current->pos = total_len;
        edge = current->vert_edge;
        total_len += edge->len;
        edge->dire = (edge->first == current);
        current = edge->getEnd();
    }

    for (int i = 0; i < p; i++) {
        rank[order[i]] = i;
    }

    vector<int> diff(p);
    int base;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        auto edge_a = find_seg(hori, vert, x, y);
        assert(edge_a != nullptr);
        auto pos_a = edge_a->get_dist(x, y);

        cin >> x >> y;

        auto edge_b = find_seg(hori, vert, x, y);
        assert(edge_b != nullptr);
        auto pos_b = edge_b->get_dist(x, y);

        if (pos_a > pos_b) {
            swap(pos_a, pos_b);
            swap(edge_a, edge_b);
        }
        long long len = pos_b - pos_a;
        int first = rank[edge_a->getStart()->index];
        int second = rank[edge_b->getStart()->index];

        if (len * 2 < total_len) {
            if (pos_a == edge_a->getStart()->pos) first--;
            if (first < 0) {
                ans[0]++;
                first = p - 1;
            }
            if (pos_b == edge_b->getEnd()->pos) second++;
            if (second == p) {
                ans[0]++;
                second = 0;
            }
            diff[first]++;
            diff[second]--;
        } else {
            ans[0]++;

            if (pos_a == edge_a->getEnd()->pos) first++;
            if (pos_b == edge_b->getStart()->pos) second--;
            diff[first]--;
            diff[second]++;
        }
    }

    for (int i = 0; i < p - 1; i++) {
        ans[i + 1] = ans[i] + diff[i];
    }
    for (int i = 0; i < p; i++) {
        cout << ans[rank[i]] << endl;
    }
    return 0;
}
