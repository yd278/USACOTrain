#include <bits/stdc++.h>

using namespace std;
#define NoS 19683
int n;
int power[9];
int avail[NoS];
int vis[25][25][NoS];
int maze[25][25];
/* encoding scheme:
    0 empty
    -1 wall
    1 M
    2 O
*/
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int decode(int i, int j, int code) {
    int p = i * 3 + j;
    return (code / power[p]) % 3;
}

int win(int code) {
    // hor
    for (int i = 0; i < 3; i++) {
        if (decode(i, 0, code) == 1 && decode(i, 1, code) == 2 &&
            decode(i, 2, code) == 2)
            return 1;
    }
    // rev_hor
    for (int i = 0; i < 3; i++) {
        if (decode(i, 0, code) == 2 && decode(i, 1, code) == 2 &&
            decode(i, 2, code) == 1)
            return 1;
    }
    // ver
    for (int j = 0; j < 3; j++) {
        if (decode(0, j, code) == 1 && decode(1, j, code) == 2 &&
            decode(2, j, code) == 2)
            return 1;
    }
    // rev_ver
    for (int j = 0; j < 3; j++) {
        if (decode(0, j, code) == 2 && decode(1, j, code) == 2 &&
            decode(2, j, code) == 1)
            return 1;
    }

    // mian diag
    if (decode(0, 0, code) == 1 && decode(1, 1, code) == 2 &&
        decode(2, 2, code) == 2)
        return 1;

    // main diag rev
    if (decode(0, 0, code) == 2 && decode(1, 1, code) == 2 &&
        decode(2, 2, code) == 1)
        return 1;

    // Anti diagonal
    if (decode(0, 2, code) == 1 && decode(1, 1, code) == 2 &&
        decode(2, 0, code) == 2)
        return 1;

    // Anti diagonal rev
    if (decode(0, 2, code) == 2 && decode(1, 1, code) == 2 &&
        decode(2, 0, code) == 1)
        return 1;

    return 0;
}

void dfs(int x, int y, int code) {
    vis[x][y][code] = 1;
    if (win(code)) {
        avail[code] = 1;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (maze[nx][ny] != -1) {
                if (maze[nx][ny] == 0) {
                    if (!vis[nx][ny][code]) dfs(nx, ny, code);
                } else {
                    int p = -1;
                    int place = maze[nx][ny];
                    while (place) {
                        place /= 3;
                        p++;
                    }
                    if (decode(p / 3, p % 3, code) == 0) {
                        if (!vis[nx][ny][code + maze[nx][ny]])
                            dfs(nx, ny, code + maze[nx][ny]);
                    } else {
                        if (!vis[nx][ny][code])  dfs(nx, ny, code);
                    }
                }
            }
        }
    }

}
int main() {
    // pre-build
    power[0] = 1;
    for (int i = 1; i < 9; i++) power[i] = power[i - 1] * 3;

    // input
    cin >> n;
    char c;
    int bx, by;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == '#') {
                cin >> c >> c;
                maze[i][j] = -1;
            } else if (c == '.') {
                cin >> c >> c;
                maze[i][j] = 0;
            } else if (c == 'M') {
                char a, b;
                cin >> a >> b;
                int p = (a - '1') * 3 + (b - '1');
                maze[i][j] = power[p];
            } else if (c == 'O') {
                char a, b;
                cin >> a >> b;
                int p = (a - '1') * 3 + (b - '1');
                maze[i][j] = power[p] * 2;
            } else if (c == 'B') {
                cin >> c >> c;
                bx = i;
                by = j;
                maze[i][j] = 0;
            }
        }
    }

    // dfs
    dfs(bx, by, 0);
    int ans = 0;
    for(int i = 0; i < NoS; i++){
        if(avail[i]) ans++;
    }
    cout << ans << endl;
}