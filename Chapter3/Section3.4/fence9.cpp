/*
ID: dyh2191
LANG: C++14
TASK: fence9
*/
#include <iostream>
using namespace std;
int gcd(int a, int b){//Assume a > b;
    if(a%b==0) return b;
    return gcd(b, a%b);
}



int main(){
    #ifndef ONLINE_JUDGE
        freopen("fence9.in","r",stdin);
        freopen("fence9.out","w",stdout);
    #endif
    int n,m,p;
    cin>>n>>m>>p;
    int dArea = m * p;
    int b = gcd(n,m) + gcd(abs(p-n),m)+p;
    cout << (dArea+2-b)/2<<endl;

}