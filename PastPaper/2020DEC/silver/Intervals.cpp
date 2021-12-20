#include <iostream>
using namespace std;
long long head[5001];
long long tail[5001];

long long fStart[10001];


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("Intervals.in","r",stdin);
    //     freopen("Intervals.out","w",stdout);
    // #endif
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        head[a]++;
        tail[b]++;
    }
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
            fStart[i+j] += head[i]*head[j];
            fStart[i+j+1]-= tail[i]*tail[j];
        }
    }

    long long ans = fStart[0];
    cout<<ans<<endl;
    for(int i = 1; i <= 2 * m; i++){
        ans += fStart[i];
        cout<<ans<<endl;
    }
    return 0;
    
}