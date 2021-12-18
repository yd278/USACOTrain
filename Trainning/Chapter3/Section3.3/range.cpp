/*
ID: dyh2191
LANG: C++14
TASK: range
*/
#include <iostream>
using namespace std;
string line;
int f[2][250][250];
int ans[250];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("range.in","r",stdin);
        freopen("range.out","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>line;
        for(int j = 0; j < n; j++){
            f[0][i][j] = (line[j] == '1');
        }
    }
    for(int k = 1; k < n; k++){
        for(int i = k ; i < n; i++){
            for(int j = k; j < n; j++){
                int kk = k % 2;
                int pk = kk ^ 1;
                f[kk][i][j] = (f[pk][i-1][j] & f[pk][i][j-1] & f[pk][i-1][j-1] &f[pk][i][j]);
                if(f[kk][i][j])ans[k]++;
            }
        }
    }
    for(int i = 1; i < n; i++){
        if(ans[i]){
            cout<<i+1<<" "<<ans[i]<<endl;
        }else break;
    }
    return 0;

}