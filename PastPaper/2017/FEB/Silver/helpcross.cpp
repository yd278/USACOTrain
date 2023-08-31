#include <bits/stdc++.h>
using namespace std;

struct boundary {
    int t;
    int index;
    bool left;
    bool operator<(const boundary &other) const {
        if (t < other.t) return true;
        if (t == other.t && left && !other.left) return true;
        return false;
    }
};

struct end_point {
    int t;
    int index;
    bool operator<(const end_point &other) const { return t > other.t; }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
#endif
    int c, n;
    cin >> c >> n;
    vector<int> chicken_t(c);
    for (int i = 0; i < c; i++) {
        cin >> chicken_t[i];
    }
    sort(chicken_t.begin(), chicken_t.end());
    vector<boundary> boundaries;
    vector<int> right_point(n);
    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        boundaries.push_back(boundary{left, i, true});
        boundaries.push_back(boundary{right, i, false});
        right_point[i] = right;
    }
    sort(boundaries.begin(), boundaries.end());
    vector<bool> matched(n);

    priority_queue<end_point> heap;
    int ans = 0;
    int cur = 0;
    for (int time : chicken_t) {
        while (boundaries[cur].t < time ||
               ((boundaries[cur].t == time) && boundaries[cur].left)) {
            auto cur_b = boundaries[cur];
            int ind = cur_b.index;
            if (cur_b.left) {
                end_point tmp = {right_point[ind], ind};
                heap.push(tmp);
            } else {
                if (!matched[ind]) heap.pop();
            }
            cur++;
        }
        if (!heap.empty()) {
            ans++;
            matched[heap.top().index] = true;
            heap.pop();
        }
    }

    cout << ans << endl;
}