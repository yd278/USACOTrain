#include <iostream>

using namespace std;
int row[13];
int diagP[26];
int diagM[26];
int n;
int rec[13];
int cnt;
void print(){
    for(int i = 0; i < n; i++){
        cout<<rec[i]+1<<" ";
    }
    cout<<endl;
}

int dfs(int x){
    if(x==n){
        if(cnt<3)print();
        cnt++;
    }
    for(int i = 0;i<n; i++){
        if(!row[i]&&!diagP[i+x]&&!diagM[x-i+n]){
            rec[x] = i;
            row[i] = 1;
            diagP[i+x] = 1;
            diagM[x-i+n] = 1;
            dfs(x+1);
            row[i] = 0;
            diagP[i+x] = 0;
            diagM[x-i+n] = 0;
        }
    }

}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("1219.in","r",stdin);
        freopen("1219.out","w",stdout);
    #endif
    cin>>n;
    dfs(0);
    cout<<cnt<<endl;
}