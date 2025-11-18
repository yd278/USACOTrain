#include <bits/stdc++.h>
using namespace std;
struct Belt {
    int x, y;
};
struct Node {
    vector<int> to;
    bool alive;
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
struct Toward {
    int n;
    int operator()(int x, int y, int dire) {
        int nx = x + dx[dire];
        int ny = y + dy[dire];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) return nx * n + ny;
        return n * n;
    }
};

int floodfill(vector<Node>& nodes, int x) {
    if (nodes[x].alive) return 0;
    nodes[x].alive = true;
    int sum = 0;
    for (auto t : nodes[x].to) {
        sum += floodfill(nodes, t);
    }
    return sum + 1;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("conveyorBelt.in", "r", stdin);
    freopen("conveyorBelt.out", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    char c;
    // 0U 1L 2D 3R
    vector<Belt> belts(q);
    vector<vector<int>> grid(n, vector<int>(n, 4));
    for (auto& b : belts) {
        cin >> b.x >> b.y;
        b.x--;
        b.y--;
        cin >> c;
        auto& g = grid[b.x][b.y];
        if (c == 'U')
            g = 0;
        else if (c == 'L')
            g = 1;
        else if (c == 'D')
            g = 2;
        else if (c == 'R')
            g = 3;
    }
    vector<Node> nodes(n * n + 1);
    Toward toward{n};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j;
            if (grid[i][j] == 4) {
                for (int k = 0; k < 4; k++) {
                    auto tow = toward(i, j, k);
                    nodes[tow].to.push_back(index);
                }
            } else {
                auto tow = toward(i, j, grid[i][j]);
                nodes[tow].to.push_back(index);
            }
        }
    }

    vector<int> ans(q);
    ans.back() = floodfill(nodes, n * n);
    for (int i = q - 1; i >= 1; i--) {
        int x = belts[i].x;
        int y = belts[i].y;
        int index = x * n + y;
        bool set_alive = false;
        for (int j = 0; j < 4; j++) {
            if (j == grid[x][y]) continue;
            auto tow = toward(x, y, j);
            nodes[tow].to.push_back(index);
            set_alive |= nodes[tow].alive;
        }
        if (set_alive) {
            ans[i - 1] = ans[i] + floodfill(nodes, index);
        } else
            ans[i - 1] = ans[i];
    }
    ans[0] = n * n + 1;
    for (auto a : ans) {
        cout << n * n - a + 1 << endl;
    }

    return 0;
}
