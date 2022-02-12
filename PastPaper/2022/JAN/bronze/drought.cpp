#include <bits/stdc++.h>
using namespace std;
long long cal(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(auto &x : h){
        cin>>x;
    }
    if(n==1)return 0;
    long long ans = 0;
    for(int i = 1; i < n -1; i++){
        if(h[i] > h[i-1]){
            int dif = h[i] - h[i-1];
            ans += 2 * dif;
            h[i] = h[i-1];
            h[i+1] -= dif;   
        }
    }
    if(h[n-1] > h[n-2]) return -1;
    for(int i = n - 2; i >= 1; i--){
        if(h[i] > h[i+1]){
            int dif = h[i] - h[i+1];
            ans += 2*dif;
            h[i] = h[i+1];
            h[i-1] -= dif;
        }
    }
    if(h[0] > h[1]) return -1;
    if(h[0]<0)return -1;
    return ans;
}
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("drought.in","r",stdin);
    //     freopen("drought.out","w",stdout);
    // #endif

    int T;
    cin>>T;
    while(T--){
        cout<<cal()<<endl;
    }
}