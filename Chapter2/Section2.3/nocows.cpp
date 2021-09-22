/*
ID: dyh2191
LANG: C++14
TASK: nocows
*/

#include <iostream>
using namespace std;
int f[200][100];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("nocows.in","r",stdin);
        freopen("nocows.out","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;

    for(int i = 1;i <=k;i++){
        f[1][i] = 1;
    }
    for(int j = 1; j <= k; j++){
        for(int i = 1; i <=n; i++){
            for(int t = 1; t < i; t += 2){
                f[i][j] += f[t][j-1] * f [i-t-1][j-1];
                f[i][j] %= 9901;
            }
        }
    }
    cout<<(f[n][k] - f[n][k-1] + 9901)%9901<<endl;
}