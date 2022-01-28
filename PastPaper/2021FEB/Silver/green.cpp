#include <bits/stdc++.h>

using namespace std;
int d[500][500];
int pre[100][500];
int grass[500][500];
int n;
long long solve(){
    long long res = 0;
    for(int i = 0; i < n; i++){
        pre[i][0] = d[i][0];
        for(int j = 1; j < n; j++){
            if(d[i][j])pre[i][j] = pre[i][j-1]+1;
            else pre[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int minLen = pre[i][j];
            long long tmp = minLen;
            for(int k = i-1; k >= 0; k--){
                if(pre[k][j] < minLen) minLen = pre[k][j];
                tmp += minLen; 
                if(minLen==0)break;
            }
            res += tmp;
        }
    }
    return res;
};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("green.in","r",stdin);
        freopen("green.out","w",stdout);
    #endif
    cin>>n;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>grass[i][j];
            d[i][j] = grass[i][j] >= 100;
        }
    }
    long long ans = solve();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = grass[i][j] > 100;
        }
    }
    ans -= solve();
    cout<<ans<<endl;
}