#include <iostream>

using namespace std;
long long a[4][100001];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("P2181.in","r",stdin);
        freopen("P2181.out","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        a[0][i] = i;
    }

    for(int i = 1; i < 4; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = a[i][j-1]+ a[i-1][j];
        }
    }
    cout<<a[3][n-3]<<endl;
}