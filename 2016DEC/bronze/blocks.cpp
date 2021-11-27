#include <iostream>
using namespace std;
int cntL[26];
int cntR[26];
int res[26];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("blocks.in","r",stdin);
        freopen("blocks.out","w",stdout);
    #endif
    int n;
    cin>>n;
    string left,right;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            cntL[j] = cntR[j] = 0;
        }
        cin>>left>>right;
        for(char x : left){
            cntL[x-'a']++;
        }
        for(char x : right){
            cntR[x-'a']++;
        }
        for(int j = 0; j < 26;j++){
            res[j] += max(cntL[j],cntR[j]);
        }

    }
    for(int i = 0; i < 26; i++){
        cout<<res[i]<<endl;
    }
}