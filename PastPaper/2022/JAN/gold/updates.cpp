#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXQ 200000

struct operate {
    char name;
    int first;
    int second;
} operates[MAXQ + 1];
struct edge {
    int first;
    int second;
    int removed;
};
vector<edge> edges(1);

int flag[MAXN + 1];
int active[MAXN + 1];
int ans[MAXN + 1];
int getFlag(int x) { return flag[x] == x ? x : flag[x] = getFlag(flag[x]); }

vector<int> graph[MAXN + 1];
void dfs(int cur, int a) {
    if(ans[cur]!=0) return;
    ans[cur] = a;
    for (auto to : graph[cur]) {
        if (ans[to] == 0) {
            dfs(to, a);
        }
    }
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("updates.in", "r", stdin);
//     freopen("updates.out", "w", stdout);
// #endif
    int n, q;
    cin >> n >> q;
    char name;
    int a, b;
    for (int i = 1; i <= n; i++) {
        active[i] = 1;
        flag[i] = i;
    }
    for (int i = 0; i < q; i++) {
        cin >> name;
        if (name == 'A') {
            cin >> a >> b;
            operates[i] = operate{name, a, b};
            edges.push_back(edge{a, b,0});
        }
        

        if (name == 'D'){
            cin>>a;
            operates[i] = operate{name,a,0};
            active[a] = 0;
        }
        if(name == 'R'){
            cin>>a;
            operates[i] = operate{name,a,0};
            edges[a].removed=1;
        }
    }
    for(auto e : edges){
        if(e.removed)continue;
        int ff = getFlag(e.first);
        int fs = getFlag(e.second);
        if(ff!=fs){
            graph[ff].push_back(fs);
            graph[fs].push_back(ff);
            flag[ff] = fs;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (active[i]) dfs(i,q);
    }
    for (int i = q - 1 ; i >= 0; i--) {
        if (operates[i].name == 'D') {
            if(ans[operates[i].first]==0)
                dfs(operates[i].first,i);
        }
        if (operates[i].name == 'R') {
            int edg_index = operates[i].first;

            int ff = getFlag(edges[edg_index].first);
            int fs = getFlag(edges[edg_index].second);
            if(ff==fs)continue;
            if(ans[ff]==0&&ans[fs]!=0){
                dfs(ff,i);
            }else if(ans[ff]!=0&&ans[fs]==0){
                dfs(fs,i);
            }

            flag[ff]= fs;
            graph[ff].push_back(fs);
            graph[fs].push_back(ff);
        }
    }
    for(int i = 1; i <= n; i++) cout<<ans[i]<<endl;
}