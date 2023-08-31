#include <bits/stdc++.h>
using namespace std;
// 0 up 1 right 2 down 3 left;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<vector<int>> label;
vector<vector<vector<bool>>> blocked;

void dfs(int x, int y, int l) {
    label[x][y] = l;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < label.size() && ny >= 0 && ny < label.size()){
            if (!blocked[x][y][i]){
                if(label[nx][ny]==0){
                    dfs(nx,ny,l);
                }
            } 
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
#endif
    int n, k, r;
    cin >> n >> k >> r;
    label.resize(n);
    for (auto &x : label) {
        x.resize(n);
    }
    blocked.resize(n);
    for (auto &x : blocked) {
        x.resize(n);
        for (auto &y : x) {
            y.resize(4);
        }
    }
    for (int i = 0; i < r; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            blocked[x1][y1][1] = 1;
            blocked[x1][y2][3] = 1;
        } else {
            if (x1 > x2) swap(x1, x2);
            blocked[x1][y1][2] = 1;
            blocked[x2][y1][0] = 1;
        }
    }
    int top = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(label[i][j]==0){
                dfs(i,j,++top);
            }
        }
    }
    vector<int> cnt(top);
    for(int i = 0; i < k; i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        cnt[label[x][y]-1]++;
    }
    int ans = 0;
    for(int x : cnt){
        ans += x * (k-x);
    }
    cout<<ans / 2<<endl;
    return 0;

}