#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
};
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
struct Scan {
    vector<vector<char>> &grid;
    vector<vector<bool>> &visited;
    vector<Point> &components;
    void dfs(int x, int y) {
        visited[x][y] = true;
        components.push_back({x, y});
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > 9) continue;
            if (ny < 0 || ny >= grid[nx].size()) continue;

            if (!visited[nx][ny] && grid[nx][ny] == grid[x][y]) dfs(nx, ny);
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<vector<char>> grid(10, vector<char>(n));
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < 10; i++) {
            cin >> grid[i][j];
        }
    }

    for (auto &col : grid) {
        for (int i = 0; i < col.size(); i++) {
            if (col[i] == '0') {
                col.resize(i);
                break;
            }
        }
    }

    bool flag = true;
    vector<vector<bool>> visited(10, vector<bool>(n));

    vector<Point> components;
    Scan scan = {grid, visited, components};
    while (flag) {
        flag = false;

        // scan

        // reset visited

        for (int i = 0; i < 10; i++) visited[i].resize(grid[i].size());
        for (auto &col : visited) fill(col.begin(), col.end(), false);
        // flood fill
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!visited[i][j]) {
                    components.clear();
                    scan.dfs(i, j);
                    if (components.size() >= k) {
                        for (auto [x, y] : components) {
                            grid[x][y] = '0';
                        }
                        flag = true;
                    }
                }
            }
        }
        if(!flag) break;
        // fall
        for (auto &col : grid) {
            int high = 0;
            int lim = col.size();
            for (int low = 0; low < col.size(); low++) {
                if (col[low] == '0') {
                    while (high < low ||
                           (high < col.size() && col[high] == '0'))
                        high++;
                    if (high == col.size()) {
                        col.resize(low);
                        break;
                    }
                    swap(col[low], col[high]);
                }
            }
        }
    }

    for (int j = n - 1; j >= 0; j--) {
        for (auto &col : grid) {
            if (j >= col.size())
                cout << '0';
            else
                cout << col[j];
        }
        cout << "\n";
    }

    return 0;
}
