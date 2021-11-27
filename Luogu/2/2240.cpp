#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int n,t;

struct coin{
    int m,v;
    double d;
}coins[100];

int cmp(coin a, coin b){
    return a.d > b.d;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("2240.in","r",stdin);
    freopen("2240.out","w",stdout);
#endif

    cin>>n>>t;
    for(int i = 0; i < n; i++){
        cin>>coins[i].m>>coins[i].v;
        coins[i].d = coins[i].v/(double)coins[i].m;
    }
    sort(coins,coins+n,cmp);
    double val = 0;
    for(int i = 0; i < n; i++){
        if(coins[i].m > t){
            val += coins[i].d * t;
            break;
        }
        val += coins[i].v;
        t -= coins[i].m;
    }
    
    cout<<fixed<<setprecision(2);
    cout<<val;
    
    

}