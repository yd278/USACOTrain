#include <bits/stdc++.h>

using namespace std;

struct Farmer {
    int index;
    long long time;
    bool operator<(const Farmer& other) const { return time > other.time; }
};
struct Node {
    set<Node*> edges;
    bool visited;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("bessiesInterview.in", "r", stdin);
    freopen("bessiesInterview.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<long long> t(n + 1);
    for (int i = 1; i <= n; i++) cin >> t[i];
    priority_queue<Farmer> pq;

    for (int i = 1; i <= k; i++) {
        pq.push({i, t[i]});
    }
    map<long long, Node> timeLine;
    for (int i = k + 1; i <= n; i++) {
        auto [index, time] = pq.top();

        pq.pop();
        pq.push({index, time + t[i]});
        timeLine[time + t[i]].edges.insert(&timeLine[time]);
    }
    auto [index, time] = pq.top();

    cout << time << endl;

    queue<Node*> q;
    q.push(&timeLine[time]);
    while (!q.empty()) {
        auto head = q.front();
        q.pop();
        head->visited = true;
        for (auto to : head->edges) {
            if (!to->visited) q.push(to);
        }
    }

    for (int i = 1; i <= k; i++) {
        if (timeLine[t[i]].visited)
            cout << "1";
        else
            cout << "0";
    }

    cout << endl;

    return 0;
}
