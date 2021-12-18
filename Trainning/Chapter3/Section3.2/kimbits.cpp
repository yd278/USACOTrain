/*
ID: dyh2191
LANG: C++14
TASK: kimbits
*/
#include <iostream>
using namespace std;
int f[32][32];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("kimbits.in","r",stdin);
        freopen("kimbits.out","w",stdout);
    #endif
    int n,l;
    long long I;
    cin>>n>>l>>I;
    for(int i = 0; i < 32; i++){
        f[i][0] = f[0][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            f[i][j] = f[i-1][j] + f[i-1][j-1];
        }
    }
    string res = "";
    n--;
    while(n){
        if(I >f[n][l]){
            res += "1";
            I-=f[n][l];
            n--;l--;
        }else{
            res += "0";
            n--;
        }
    }
    res+=(I==1)?"0":"1";
    cout<<res<<endl;
}