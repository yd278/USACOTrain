/*
ID: dyh2191
LANG: C++14
TASK: castle
*/

#include <iostream>
#include <vector>
using namespace std;

int map[51][51];
int label[51][51];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int area[2550];

int floodfill(int x, int y, int l) {
    if (label[x][y]) return 0;
    label[x][y] = l;
    int res = 1;
    for (int i = 0; i < 4; i++) {
        if (!(map[x][y] & (1 << i))) {
            res += floodfill(x + dx[i], y + dy[i], l);
        }
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
#endif
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (label[i][j] == 0) {
                cnt++;
                int a = floodfill(i, j, cnt);
                area[cnt] = a;
            }
        }
    }

    int maxi = 0;
    for (int i = 1; i <= cnt; i++)
        if (area[i] > maxi) maxi = area[i];

    cout << cnt << endl;
    cout << maxi << endl;

    int roomi, roomj;
    char wall;
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (i - 1 >= 0)
                if (label[i][j] != label[i - 1][j]) {
                    if (area[label[i][j]] + area[label[i - 1][j]] > maxi) {
                        maxi = area[label[i][j]] + area[label[i - 1][j]];
                        roomi = i;
                        roomj = j;
                        wall = 'N';
                    }
                }

            if (j + 1 < m)
                if (label[i][j] != label[i][j + 1]) {
                    if (area[label[i][j]] + area[label[i][j + 1]] > maxi) {
                        maxi = area[label[i][j]] + area[label[i][j + 1]];
                        roomi = i;
                        roomj = j;
                        wall = 'E';
                    }
                }
        }
    }
    cout << maxi << endl;
    cout << roomi + 1 << " " << roomj + 1 << " " << wall << endl;
    return 0;
}