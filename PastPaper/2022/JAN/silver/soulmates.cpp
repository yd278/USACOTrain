#include <bits/stdc++.h>
using namespace std;
int check(long long a, long long b){
    if(a>b)return -1;
    int min = 2147483647;
    int steps = 0;
    while(b>=a){

        if((b - a + steps) < (long long)min) min = b - a + steps;
        if(b&1)steps += 2;
        else steps++;
        b>>=1;
    }
    return min;
}
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("soulmates.in","r",stdin);
    //     freopen("soulmates.out","w",stdout);
    // #endif
    int T;
    cin>>T;
    while(T--){
        long long a,b;
        cin>>a>>b;
        int min = 2147483647;
        int steps = 0;
        while(a){
            int t = check(a,b);
            if(t!=-1){
                if( t + steps < min) min = t + steps;
            }
            if(a==1)break;
            if(a&1){
                a+=1;
                steps++;
            }
            a>>=1;
            steps++;
        }
        cout<<min<<endl;
    }

}