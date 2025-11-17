#include <bits/stdc++.h>
using namespace std;
inline int encode(char c) {
    if (c >= 'a') return c - 'a';
    return c - 'A' + 26;
}
bool findCircle(int self, int x, vector<int>& to, vector<bool>& visited,
                vector<int>& inDeg) {
    if (inDeg[x] != 1) return false;
    if (visited[x]) return (self == x);
    visited[x] = true;
    return findCircle(self, to[x], to, visited, inDeg);
}

void process() {
    string s;
    string t;
    cin >> s >> t;
    if (s == t) {
        cout << 0 << endl;
        return;
    }
    int n = s.length();
    vector<int> to(52, -1);
    vector<int> inDeg(52);
    vector<bool> app(52);
    for (int i = 0; i < n; i++) {
        int start = encode(s[i]);
        int target = encode(t[i]);
        app[target] = true;
        if (to[start] == -1) {
            to[start] = target;
        } else if (to[start] == target)
            continue;
        else {
            cout << -1 << endl;
            return;
        }
    }
    bool full = true;
    for (auto a : app) full &= a;
    if (full) {
        cout << -1 << endl;
        return;
    }
    int edges = 0;
    for (int i = 0; i < 52; i++) {
        if (to[i] == i) {
            to[i] = -1;
        }
        if (to[i] != -1) {
            inDeg[to[i]]++;
            edges++;
        }
    }

    vector<bool> visited(52);
    int cnt = 0;
    for (int i = 0; i < 52; i++) {
        if (!visited[i]) cnt += findCircle(i, i, to, visited, inDeg);
    }
    cout << edges + cnt << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("findAndReplace.in", "r", stdin);
    freopen("findAndReplace.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}
