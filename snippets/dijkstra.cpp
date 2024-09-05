#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
    int len;
};
struct Dist {
    int nodeIndex;
    int dist;
    bool operator<(const Dist& other) const { return dist < other.dist; }
};
vector<vector<Edge>> edges;
vector<Dist> distHeap;
vector<int> posInHeap;
#define dh distHeap
#define pih posInHeap
#define ni nodeIndex
void pushUp(int x) {
    while (x > 1) {
        if (dh[x] < dh[x >> 1]) {
            swap(dh[x], dh[x >> 1]);
            pih[dh[x].ni] = x;
            pih[dh[x >> 1].ni] = x >> 1;
        } else {
            break;
        }
        x = x >> 1;
    }
}
void pushDown(int x) {
    bool flag = true;
    while (flag) {
        flag = false;
        if (x << 1 > tail) return;
        if ((x << 1 | 1) > tail) {
            if (dh[x << 1] < dh[x]) {
                swap(dh[x << 1], dh[x]);
                pih[dh[x].ni] = x;
                pih[dh[x << 1].ni] = x << 1;
                x = x << 1;
            }
            return;
        }
        int smaller = dh[x << 1] < dh[x << 1 | 1] ? x << 1 : (x << 1 | 1);
        if (dh[smaller] < dh[x]) {
            swap(dh[smaller], dh[x]);
            pih[dh[x].ni] = x;
            pih[dh[smaller].ni] = smaller;
            flag = true;
        }
        x = smaller;
    }
}
void decreaseKey(int i, double newV) {
    int p = pih[i];
    dh[p].dist = newV;
    pushUp(p);
}
void pop() {
    swap(dh[1], dh[tail]);
    pih[dh[1].ni] = 1;
    pih[dh[tail].ni] = tail;
    tail--;
    if (tail) {
        pushDown(1);
    }
}
int getDist(int x) { return distHeap[pih[x]].dist; }
#define gd getDist


int main() {

#ifndef ONLINE_JUDGE
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);
#endif
	int n,m,s;
	cin>>n>>m>>s;
	int a,b,c;
	for(int i = 0; i < m; i++){
		cin>>a>>b>>c;
		edges[a].push_back({b,c});
	}

}