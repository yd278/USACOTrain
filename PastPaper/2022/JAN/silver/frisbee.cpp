#include <bits/stdc++.h>
using namespace std;

struct cow{
    int index;
    int hight;
};

stack<cow> mono;
int h[300000];
int n;
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("frisbee.in","r",stdin);
    //     freopen("frisbee.out","w",stdout);
    // #endif
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>h[i];
    }
    long long ans = 0;
    mono.push(cow{0,h[0]});
    for(int i = 1; i < n; i++){
        while(!mono.empty() && mono.top().hight < h[i]) mono.pop();
        if(!mono.empty()){
            ans += i - mono.top().index + 1;
        }
        mono.push(cow{i,h[i]});
    }

    while(!mono.empty()) mono.pop();
    mono.push(cow{n-1, h[n-1]});
    for(int i = n-2; i >= 0; i--){
        
        while(!mono.empty() && mono.top().hight < h[i]) mono.pop();
        if(!mono.empty()){
            ans += mono.top().index - i + 1;
        }
        mono.push(cow{i,h[i]});
    }
    cout<<ans<<endl;
    return 0;
}