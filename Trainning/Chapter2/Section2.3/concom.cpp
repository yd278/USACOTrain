/*
ID: dyh2191
LANG: C++14
TASK: concom
*/
#include <iostream>
using namespace std;
int stock[101][101];
int tot[101];
int visited[101];
int con[101];
int m;
void dfs(int x) {
    if (visited[x]) return;
    visited[x] = 1;
    for (int i = 1; i <= m; i++) {
        tot[i] += stock[x][i];
        if (tot[i] > 50) {
            con[i] = 1;
            dfs(i);
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        stock[a][b] = c;
        m = a > m ? a : m;
        m = b > m ? b : m;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            tot[j] = visited[j] = con[j] = 0;
        }
        dfs(i);
        for(int j = 1; j <= m; j++){
            if(con[j] && j!=i){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}