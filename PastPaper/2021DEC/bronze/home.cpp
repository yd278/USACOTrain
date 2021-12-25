/*
Credit to 路策
Congratulations on his promotion to the silver div.
*/

#include <cstdio>
#define MAXN 51

int t; 
int n, k, G[MAXN][MAXN], C[MAXN][MAXN]; char ci; 

void dfs(int x, int y, int t, int d){
    if (t > k || y >= n || x >= n || G[x][y]) return; 
    C[x][y]++; 
    if (d == 1) {
        dfs(x, y + 1, t, 1); 
        dfs(x + 1, y, t + 1, 0); 
    }
    else {
        dfs(x + 1, y, t, 0); 
        dfs(x, y + 1, t + 1, 1); 
    }
}

void run(){
    scanf("%d %d\n", &n, &k); 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%c", &ci); 
            if (ci == 'H') G[i][j] = 1; 
            else G[i][j] = 0; 
            C[i][j] = 0; 
        }
        scanf("\n"); 
    }
    dfs(0, 1, 0, 1); 
    dfs(1, 0, 0, 0); 
    printf("%d\n", C[n - 1][n - 1]); 
}

int main(){
    scanf("%d", &t); 
    for (int i = 0; i < t; i++){
        run(); 
    }
}