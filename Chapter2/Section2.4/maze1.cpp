/*
ID: dyh2191
LANG: C++14
TASK: maze1
*/
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

char map[250][100];
int dist[250][100];
int maxDist;
int Ex[2];
int Ey[2];
int w, h;
int res;

struct pos {
    int x, y;
};
queue<pos> q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
#endif
    string line;
    cin >> w >> h;
    getchar();
    for (int i = 0; i < 2 * h + 1; i++) {
        for (int j = 0; j < 2 * w + 1; j++) {
            map[i][j] = getchar();
        }
        getchar();
    }
    // find exit

    int cnt = 0;
    for (int i = 0; i < 2 * h + 1; i++) {
        if (map[i][0] == ' ') {
            Ex[cnt] = i;
            Ey[cnt] = 1;
            cnt++;
        }
        if (map[i][2 * w] == ' ') {
            Ex[cnt] = i;
            Ey[cnt] = 2 * w - 1;
            cnt++;
        }
    }
    for (int j = 0; j < 2 * w + 1; j++) {
        if (map[0][j] == ' ') {
            Ex[cnt] = 1;
            Ey[cnt] = j;
            cnt++;
        }
        if (map[2 * h][j] == ' ') {
            Ex[cnt] = 2 * h - 1;
            Ey[cnt] = j;
            cnt++;
        }
    }

    for (int i = 0; i < 2 * h + 1; i++) {
        for (int j = 0; j < 2 * w + 1; j++) {
            dist[i][j] = 2147483647;
        }
    }
    q.push(pos{Ex[0], Ey[0]});
    q.push(pos{Ex[1],Ey[1]});
    dist[Ex[0]][Ey[0]] = 1;
    dist[Ex[1]][Ey[1]] = 1;
    while (!q.empty()) {
        pos current = q.front();
        q.pop();
        int x = current.x;
        int y = current.y;
        if ((x + 2 < h * 2 + 1) && (map[x + 1][y] == ' ')) {
            if (dist[x + 2][y] > dist[x][y] + 1) {
                dist[x + 2][y] = dist[x][y] + 1;
                q.push(pos{x + 2, y});
            }
        }
        if ((x - 2 >= 0) && (map[x - 1][y] == ' ')) {
            if (dist[x - 2][y] > dist[x][y] + 1) {
                dist[x - 2][y] = dist[x][y] + 1;
                q.push(pos{x - 2, y});
            }
        }
        if ((y + 2 < w * 2 + 1) && (map[x][y + 1] == ' ')) {
            if (dist[x][y + 2] > dist[x][y] + 1) {
                dist[x][y + 2] = dist[x][y] + 1;
                q.push(pos{x, y + 2});
            }
        }
        if ((y - 2 >= 0) && (map[x][y - 1] == ' ')) {
            if (dist[x][y - 2] > dist[x][y] + 1) {
                dist[x][y - 2] = dist[x][y] + 1;
                q.push(pos{x, y - 2});
            }
        }
    }


    for(int i = 1; i < 2*h; i+=2){
        for(int j = 1; j < 2 * w; j += 2){
            if(dist[i][j]>maxDist){
                maxDist = dist[i][j];
            }
        }
    }
    cout << maxDist << endl;
}