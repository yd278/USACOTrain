#include <bits/stdc++.h>
using namespace std;

struct Drop {
    int y, x;
    int index;
};

vector<Drop> drops;
deque<Drop> max_q;
deque<Drop> min_q;

inline void push_max(int i) {
    while (!max_q.empty() && max_q.back().y < drops[i].y) max_q.pop_back();
    max_q.push_back(drops[i]);
}

inline void push_min(int i) {
    while (!min_q.empty() && min_q.back().y > drops[i].y) min_q.pop_back();
    min_q.push_back(drops[i]);
}

inline void pop_max(int i) {
    if (max_q.front().index == i) max_q.pop_front();
}

inline void pop_min(int i) {
    if (min_q.front().index == i) min_q.pop_front();
}

inline int get_max() { return max_q.front().y; }

inline int get_min() { return min_q.front().y; }

bool cmp(Drop a, Drop b) { return a.x < b.x; }

int main() {
#ifndef ONLINE_JUDGE
    freopen("2698.in", "r", stdin);
    freopen("2698.out", "w", stdout);
#endif
    int ans = INT_MAX;
    int n, d;
    cin >> n >> d;
    drops.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> drops[i].x >> drops[i].y;
    }
    sort(drops.begin(), drops.end(), cmp);
    for (int i = 0; i < n; i++) {
        drops[i].index = i;
    }
    push_max(0);
    push_min(0);
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (get_max() - get_min() < d && r < n - 1) {
            r++;
            push_max(r);
            push_min(r);
        }
        if (get_max() - get_min() >= d) ans = min(ans, drops[r].x - drops[l].x);
        if (r == n - 1) break;
        pop_max(l);
        pop_min(l);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
}