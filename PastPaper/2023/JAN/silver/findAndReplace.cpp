#include <bits/stdc++.h>
using namespace std;
inline int encode(char c) {
    if (c >= 'a') return c - 'a';
    return c - 'A' + 26;
}
int getFlag(int x, vector<int> &flag, vector<bool> &circle) {
    if (flag[x] == x) return x;
    circle[flag[x]] = circle[flag[x]] || circle[x];
    int tmp = getFlag(flag[x], flag, circle);
    flag[x] = tmp;
    return tmp;
}

void merge(int x, int y, vector<int> &flag, vector<bool> &circle) {
    x = getFlag(x, flag, circle);
    y = getFlag(y, flag, circle);
    if (x == y) return;
    flag[x] = y;
    circle[x] = circle[x] || circle[y];
}
bool dfs(int x, vector<int> &to, vector<int> &flag, vector<bool> &circle,
         vector<bool> &visited) {
    if (visited[x]) return true;
    if (to[x] == -1) return false;
    visited[x] = true;
    bool res = dfs(to[x], to, flag, circle, visited);
    if (res) circle[x] = circle[to[x]] = true;
    merge(x, to[x], flag, circle);
    visited[x] = false;
    return res;
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
    for (int i = 0; i < n; i++) {
        int start = encode(s[i]);
        int target = encode(t[i]);
        if (to[start] == -1) {
            to[start] = target;
            inDeg[target]++;
        } else if (to[start] == target)
            continue;
        else {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < 52; i++)
        if (to[i] == i) to[i] = -1;
    bool full = true;
    for (int i = 0; i < 52; i++) {
        full &= inDeg[i];
    }
    if (full) {
        cout << -1 << endl;
        return;
    }
    vector<int> flag(52);

    vector<bool> circle(52);
    vector<bool> visited(52);
    for (int i = 0; i < 52; i++) {
        flag[i] = i;
    }

    for (int i = 0; i < 52; i++) {
        if (inDeg[i] == 0) {
            dfs(i, to, flag, circle, visited);
        }
    }
    int pureCir = 0;
    for (int i = 0; i < 52; i++) {
        if ((flag[i] == i) && (!circle[i]) && (to[i] != -1)) {
            dfs(i, to, flag, circle, visited);
            pureCir++;
        }
    }
    int ans = 0;
    vector<int> cnt(52);
    for (int i = 0; i < 52; i++) cnt[getFlag(i, flag, circle)]++;
    for (int i = 0; i < 52; i++) {
        if (cnt[i]) {
            if (circle[i])
                ans += cnt[i];
            else
                ans += cnt[i] - 1;
        }
    }
    ans += pureCir;
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}
