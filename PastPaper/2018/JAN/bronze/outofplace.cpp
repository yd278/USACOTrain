#include<iostream>
#include <algorithm>
using namespace std;
int a[101];
int b[101];
int n;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("outofplace.in","r",stdin);
        freopen("outofplace.out","w",stdout);
    #endif
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i]!=b[i])cnt++;
    }
    cout<<cnt-1<<endl;
}