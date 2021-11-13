#include <iostream>
using namespace std;
long long f[21][21];
int hx, hy;
int control(int x, int y) {
    int dx = abs(x - hx);
    int dy = abs(y - hy);
    if(dy==2&&dx==1)return 1;
    if(dy==1&&dx==2)return 1;
    if(dy==0&&dx==0)return 1;
    return 0;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("1002.in","r",stdin);
        freopen("1002.out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m>>hx>>hy;
    f[0][0] = 1;
    for(int i = 1; i <=n ; i++){
        f[i][0] = f[i-1][0];
        if(control(i,0))f[i][0] = 0;
    }
    for(int j = 1; j <= m; j++){
        f[0][j] = f[0][j-1];
        if(control(0,j))f[0][j] = 0;
    } 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            f[i][j] = f[i-1][j] + f[i][j-1];
            if(control(i,j))f[i][j] = 0;
        }
    }
    cout<<f[n][m]<<endl;
}