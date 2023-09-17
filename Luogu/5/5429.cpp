#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x, y;
};

struct Boundary {
    int maxX, maxY, minX, minY;
    int cir() { return 2 * (maxX - minX + maxY - minY); }
};
vector<Cow> cows;
vector<vector<int>> edges;
vector<int> label;
void floodfill(Boundary &b, int cur, int l) {
    if(cows[cur].x < b.minX)b.minX = cows[cur].x;
    if(cows[cur].x > b.maxX)b.maxX = cows[cur].x;
    if(cows[cur].y < b.minY)b.minY = cows[cur].y;
    if(cows[cur].y > b.maxY)b.maxY = cows[cur].y;
    label[cur] = l;
    for(int to : edges[cur]){
        if(label[to]==0){
            floodfill(b,to,l);
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("5429.in", "r", stdin);
    freopen("5429.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    cows.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    edges.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    label.resize(n + 1);
    vector<Boundary> boundaries;
    int l = 1;
    for (int i = 1; i <= n; i++) {
        if (label[i] == 0) {
            Boundary b;
            b.maxX = INT_MIN;
            b.maxY = INT_MIN;
            b.minX = INT_MAX;
            b.minY = INT_MAX;
            floodfill(b, i, l);
            boundaries.push_back(b);
            l++;
        }
    }
    int ans = INT_MAX;
    for(auto &b : boundaries){
        int tmp = b.cir();
        if(tmp < ans) ans = tmp;
    }
    cout<<ans<<endl;
    return 0;
}