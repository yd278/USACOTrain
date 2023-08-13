/*
ID: dyh2191
LANG: C++14
TASK: camelot
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXR 30
#define MAXC 26
#define MAXN 780
int R, C;
int dR[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dC[8] = {1, 2, 2, 1, -1, -2, -2, -1};
inline int encode(int r, int c, int s) { return s * R * C + r * C + c; }
inline int decodeR(int x) { return (x / C) % R; }
inline int decodeC(int x) { return x % C; }
inline int decodeS(int x) { return x % (R * C); }

struct edge {
    int to, len;
};

struct node {
    int id;
    int dist;

    vector<edge> edges;
    bool operator<(const node &other) const { return dist > other.dist; }
};

node nodes[2 * MAXN];
int visited[2 * MAXN];
int kingR, kingC;
inline int kingDist(int r, int c) {
    return max(abs(kingR - r), abs(kingC - c));
}
int knightsR[MAXN];
int knightsC[MAXN];
int knightTail;

int dijkstra(int source){
    priority_queue<node> q;
    for(int i = 0; i < R*C*2;i++){
        visited[i] = 0;
        nodes[i].dist=1000000;
    }
    nodes[source].dist = 0;
    q.push(nodes[source]);

    while(!q.empty()){
        node qh = q.top();
        q.pop();
        int index = qh.id;
        if(!visited[index]){
            visited[index]=1;
            for(auto e : qh.edges){
                int to = e.to;
                int len = e.len;

                if(nodes[to].dist > qh.dist + len){
                    nodes[to].dist = qh.dist+len;
                    q.push(nodes[to]);
                }
            }
        }
    }
    int sum = 0;
    int minDiff = INT_MAX;
    for(int i = 0; i < knightTail;i++){
        int knight0 = encode(knightsR[i],knightsC[i],0);
        int knight1 = encode(knightsR[i],knightsC[i],1);
        sum += nodes[knight0].dist;
        int diff = nodes[knight1].dist-nodes[knight0].dist;
        if(minDiff > diff){
            minDiff = diff;
        }
    }
    int dis = kingDist(decodeR(source),decodeS(source));
    if(dis<minDiff) minDiff = dis;
    return sum + minDiff;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);
#endif

    cin >> R >> C;
    char c;
    int r;
    cin >> c >> r;
    kingC = c - 'A';
    kingR = r - 1;
    while (cin >> c) {
        cin >> r;
        knightsC[knightTail] = c - 'A';
        knightsR[knightTail] = r - 1;
        knightTail++;
    }

    for(int i = 0; i < R*C*2;i++){
        nodes[i].id = i;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int cur0 = encode(i,j,0);
            int cur1 = encode(i,j,1);
            for(int k = 0; k < 8; k++){
                int nR = i + dR[k];
                if(nR<R && nR >= 0){
                    int nC = j + dC[k];
                    if(nC<C && nC>=0){
                        int to0 = encode(nR,nC,0);
                        nodes[cur0].edges.push_back(edge{to0,1});
                        int to1 = encode(nR,nC,1);
                        nodes[cur1].edges.push_back(edge{to1,1});
                    }
                }
            }
            nodes[cur0].edges.push_back(edge{cur1,kingDist(i,j)});
        }
    }
    int minAns = INT_MAX;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            int source = encode(i,j,0);
            int tmp = dijkstra(source);
            if(tmp < minAns)minAns = tmp;
        }
    }
    cout<<minAns<<endl;
}