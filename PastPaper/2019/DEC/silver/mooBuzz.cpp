#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("moobuzz.in","r",stdin);
        freopen("moobuzz.out","w",stdout);
    #endif
    int shift[8] = {1,2,4,7,8,11,13,14};
    int n;
    cin>>n;
    n--;
    int q = n / 8;
    int r = n % 8;
    int ans = q *15 + shift[r];
    cout<<ans<<endl;
    return 0;
}
