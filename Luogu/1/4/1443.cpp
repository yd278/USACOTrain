#include <bits/stdc++.h>

using namespace std;
int steps[400][400];

struct pos {
    int x, y;
};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int main() {
#ifndef ONLINE_JUDGE
    freopen("1443.in", "r", stdin);
    freopen("1443.out", "w", stdout);
#endif
    int n, m;
    int x, y;
    cin >> n >> m >> x >> y;
    x--;
    y--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            steps[i][j] = -1; //-1 表示还没走到
        }
    }
    queue<pos> q;
    q.push(pos{x, y});
    steps[x][y] = 0;
    while (!q.empty()) {
        auto head = q.front();
        for (int d = 0; d < 8; d++) {  // 枚举队首位置可以到达的所有位置
            int nx = head.x + dx[d];
            int ny = head.y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {  // 如果位置合法
                if (steps[nx][ny] ==
                    -1) {  // if(!visited[nx][ny]) 且之前未搜到过
                    steps[nx][ny] = steps[head.x][head.y] + 1;  // 记录步数
                    q.push(pos{nx, ny});  // 放进队列里
                }
            }
        }
        q.pop();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%-5d", steps[i][j]);
        printf("\n");
    }
    return 0;
}