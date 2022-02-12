#include <iostream>
using namespace std;
int leg[50000]; // 2: (, 1:)
int main(){
    #ifndef ONLINE_JUDGE
        freopen("cowfind.in","r",stdin);
        freopen("cowfind.out","w",stdout);
    #endif
    string s;
    cin>>s;
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i+1]){
            leg[i] = (s[i] - '(')?1:2;
        }
    }
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < s.length() - 1; i++){
        if(leg[i] == 2) cnt++;
        if(leg[i] == 1) sum+=cnt;
    }
    cout<<sum<<endl;
}