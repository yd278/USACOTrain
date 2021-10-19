/*
ID: dyh2191
LANG: C++14
TASK: fence
*/
#include <iostream>
#include <stack>
using namespace std;
int map[501][501];
int count[501];
stack<int> ans;
int f;
int min_n, max_n;
void print(){
    while(!ans.empty()){
        cout<<ans.top()<<endl;
        ans.pop();
    }
}
void dfs(int x) {

    for (int i = min_n; i <= max_n; i++) {
        if (map[x][i]) {
            map[x][i]--;
            map[i][x]--;
            dfs(i);

        }
    }
    ans.push(x);
    return;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("fence.in","r",stdin);
        freopen("fence.out","w",stdout);
    #endif
    cin >> f;
    int a, b;
    min_n = 550;
    max_n = 0;
    for (int i = 0; i < f; i++) {
        cin >> a >> b;
        map[a][b]++;
        map[b][a]++;
        min_n = min(min_n, min(a, b));
        max_n = max(max_n, max(a, b));
    }
    for (int i = min_n; i <= max_n; i++) {
        for (int j = min_n; j <= max_n; j++) {
            count[i] += map[i][j];
        }
    }
    for (int i = min_n; i <= max_n; i++) {
        if (count[i] % 2 == 1) {
            dfs(i);
            print();
            return 0;
        }
    }
    dfs(min_n);
    print();
    return 0;
}