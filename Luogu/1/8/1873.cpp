#include <iostream>
using namespace std;
int n;
long long m;
long long h[1000000];
int check(int hight){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(h[i] > hight) sum += h[i] - hight;
    }
    return sum >= m;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1873.in","r",stdin);
    freopen("1873.out","w",stdout);

#endif

    cin>>n>>m;
    int r = 0;
    for(int i = 0; i < n; i++){
        cin>>h[i];
        if(h[i]>r)r = h[i];
    }
    int l = 0;
    int mid;
    while(r-l>1){
        mid = (l+r)/2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    if(check(r))l = r;
    cout<<l<<endl;



}