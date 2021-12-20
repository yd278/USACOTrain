#include <iostream>
using namespace std;
string s;
int n;
int Prev[500000];
int Next[500000];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("photo.in","r",stdin);
        freopen("photo.out","w",stdout);
    #endif
    cin>>n;
    cin>>s;
    int prevG = -1;
    int prevH = -1;
    for(int i = 0; i < n; i++){
        if(s[i]=='G'){
            Prev[i] = prevG;
            prevG = i;
        }else{
            Prev[i] = prevH;
            prevH = i;
        }
    }
    int nextG = n;
    int nextH = n;
    for(int i = n-1; i>=0; i--){
        
        if(s[i]=='G'){
            Next[i] = nextG;
            nextG = i;
        }else{
            Next[i] = nextH;
            nextH = i;
        }
    }
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += (long long)(i-Prev[i]) * (long long)(Next[i] - i);
    }
    sum -= n;
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(s[i]!=s[i-1])cnt++;
    }
    sum -= cnt;
    cout<<sum<<endl;
    return 0;
}