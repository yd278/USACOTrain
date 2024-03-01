#include <bits/stdc++.h>

#include <vector>
using namespace std;
struct Cow {
    long long a;
    int cnt = 1;
    int indeg = 0;
    vector<int> out;
    Cow() { out.reserve(2); }
};
int main() {

    int n;
    cin >> n;
    vector<Cow> cows(n);
    for (auto &c : cows) cin >> c.a;
    for (int i = 0; i < n; i++) {
        int u = (i + 1 == n ? 0 : i + 1), v = i;
        if (cows[v].a > cows[u].a) swap(u, v);
        cows[v].indeg++;
        cows[u].out.push_back(v);
    }

    long long sum = 0;
    for (auto &c : cows) {
        sum += c.a;
    }
    set<int> sinks;
    vector<vector<int>> source(2);
    for (auto &s : source) s.reserve(n);
    for (int i = 0; i < n; i++) {
        if (cows[i].indeg == 2) sinks.insert(i);
        if (cows[i].indeg == 0) source[0].push_back(i);
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (flag) {
            cout << sum << "\n";
            continue;
        }
        for (int e : sinks) {
            sum += cows[e].a;
            cows[e].cnt++;
        }
        auto &curSr = source[i % 2];
        auto &nxtSr = source[(i + 1) % 2];
        nxtSr.clear();
        for (int s : curSr) {
            sum -= cows[s].a;
            if (cows[s].cnt > 1) {
                cows[s].cnt--;
                nxtSr.push_back(s);
            }

            else {
                int u = cows[s].out[0];
                int v = cows[s].out[1];
                if (u != v) {
                    if (cows[v].a > cows[u].a) swap(u, v);
                    if (cows[u].indeg == 2) sinks.erase(u);
                    cows[u].indeg--;
                    if (cows[u].indeg == 0) nxtSr.push_back(u);
                    cows[u].out.push_back(v);
                } else
                    flag = true;
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
