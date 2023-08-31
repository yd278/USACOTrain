#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n;
    cin >> c >> n;
    vector<int> dist(1 << c, INT_MAX / 2);
    vector<int> team;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < c; j++) {
            tmp *= 2;
            char ch;
            cin >> ch;
            if (ch == 'G') tmp++;
        }
        team.push_back(tmp);
        dist[tmp] = 0;
    }
    for (int k = 0; k < c; k++) {
        for (int i = 0; i < c; i++) {
            for (int x = 0; x < (1 << c); x++) {
                if (dist[x] > dist[x ^ (1 << i)] + 1) {
                    dist[x] = dist[x ^ (1 << i)] + 1;
                }
            }
        }
    }
    for (int t : team) {
        cout << c - dist[(1 << c) - 1 - t] << endl;
    }
    return 0;
}