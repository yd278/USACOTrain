#include <iostream>
#include <queue>
using namespace std;
int k[201];
int step[201];
queue<int> q;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("1135.in","r",stdin);
        freopen("1135.out","w",stdout);
    #endif
    int n,a,b;
    cin>>n>>a>>b;
    for(int i = 1; i <= n; i++){
        cin>>k[i];
        step[i] = -1;
    }
    q.push(a);
    step[a] = 0;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        int up = c + k[c];
        if(up <= n){
            if(step[up]==-1){
                step[up] = step[c]+1;
                q.push(up);
            }
        }
        int down = c - k[c];
        if(down > 0){
            if(step[down]==-1){
                step[down] = step[c] + 1;
                q.push(down);
            }
        }
    }
    cout<<step[b]<<endl;
}