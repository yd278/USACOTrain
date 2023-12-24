#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    int depth = 0;
    long long labelSum = 0;
    long long prevLabel = INTMAX_MAX;
    int prevNode = 0;
    int rank;
    int inDeg = 0;


};

vector<Node> nodes;
struct Edge {
    int to;
    long long label;
    bool operator<(const Edge& other) const { return label > other.label; }
};
bool cmp(const int &a, const int &b){
    auto aN = nodes[a];
    auto bN = nodes[b];
    if(aN.prevLabel > bN.prevLabel) return true;
    if(aN.prevLabel==bN.prevLabel){
        if(nodes[aN.prevNode].rank < nodes[bN.prevNode].rank) return true;
    }
    return false;
}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("MinimumLongestTrip.in", "r", stdin);
//     freopen("MinimumLongestTrip.out", "w", stdout);
// #endif
    int n, m;
    cin >> n >> m;
    nodes.resize(n);
    vector<vector<Edge>> edges(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long l;
        cin >> a >> b >> l;
        edges[b - 1].push_back({a - 1, l});
        nodes[a - 1].inDeg++;
    }

    vector<int> cur;
    cur.reserve(n);
    for(int i = 0; i < n; i++){
        if(nodes[i].inDeg==0){
            cur.push_back(i);
        }
    }
    for(int i = 0; i < cur.size(); i++){
        nodes[cur[i]].rank = i;
    }
    
    vector<int> nxt;
    nxt.reserve(n);

    while(!cur.empty()){
        nxt.clear();
        for(auto vi : cur){
            for(auto e: edges[vi]){
                int to = e.to;
                int depth = nodes[vi].depth+1;
                if(nodes[to].depth<depth || (nodes[to].depth== depth && nodes[to].prevLabel>=e.label)){
                    nodes[to].depth = depth;
                    nodes[to].labelSum = nodes[vi].labelSum + e.label;
                    nodes[to].prevLabel = e.label;
                    nodes[to].prevNode = vi;
                }

                nodes[to].inDeg--;
                if(nodes[to].inDeg==0)nxt.push_back(to);
            }
        }
        sort(nxt.begin(),nxt.end(),cmp);
        for(int i = 0; i < nxt.size(); i++){
            nodes[nxt[i]].rank = i;
        }
        cur = nxt;
        
    }
    for (int i = 0; i < n; i++) {
        cout << nodes[i].depth << " " << nodes[i].labelSum << "\n";
    }

    return 0;
}
