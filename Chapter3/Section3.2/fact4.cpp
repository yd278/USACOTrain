/*
ID: dyh2191
LANG: C++14
TASK: fact4
*/
#include <iostream>
using namespace std;
int cnt2,cnt5;
int n;
int res;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("fact4.in","r",stdin);
        freopen("fact4.out","w",stdout);
    #endif
    cin>>n;
    for(int i = 1; i <= n; i++){
        int t = i;
        while(t%5==0){
            cnt5++;
            t/=5;
        }
    }
    cnt2 = cnt5;
    res = 1;
    for(int i = 1; i <=n; i++){
        res *= i;
        while(cnt5>0 && (res%5==0)){
            res /= 5;
            cnt5--;
        }
        while(cnt2>0&&(res%2==0)){
            res/=2;
            cnt2--;
        }
        res%=10;
    }
    cout<<res<<endl;
}