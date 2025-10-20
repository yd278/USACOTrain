#include <bits/stdc++.h>
using namespace std;
int main() {
    int c, n;
    cin >> c >> n;
    vector<int> dist(1 << c, INT_MAX / 2);
    vector<int> team;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < c; j++) {
            tmp *= 2;
            char ch;
            cin >> ch;
            if (ch == 'G') tmp++;
        }
        team.push_back(tmp);
        q.push(tmp);
        dist[tmp] = 0;
    }
    while (!q.empty()) {
        int qh = q.front();
        int d = dist[qh];
        q.pop();
        for (int i = 0; i < c; i++) {
            if (dist[qh ^ (1 << i)] > d + 1) {
                dist[qh ^ (1 << i)] = d + 1;
                q.push(qh ^ (1 << i));
            }
        }
    }

    for (int t : team) {
        cout << c - dist[(1 << c) - 1 - t] << endl;
    }
    return 0;
}
