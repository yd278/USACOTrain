#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("HighCardwins.in","r",stdin);
        freopen("HighCardwins.out","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<bool> Elsie(2*n+1);
    int cnt = 0;
    int a;
    for(int i = 0; i < 2*n; i++){
        cin>>a;
        Elsie[a] = true;
    }
    for(int i = 1; i <= 2 * n ;i++){
        if(Elsie[i])cnt++;
        else{
            if(cnt!=0)cnt--;
        }
    }
    cout<<n-cnt<<endl;

    return 0;
}
