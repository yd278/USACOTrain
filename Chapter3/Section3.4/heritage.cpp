/*
ID: dyh2191
LANG: C++14
TASK: heritage
*/
#include <iostream>
using namespace std;
string in;
string pre;
void post(int inL, int inR, int preL, int preR){
    if(inL==inR)return;
    char root = pre[preL];
    if(inR-inL >1){
        for(int i = inL; i < inR; i++){
            if(in[i]==root){
                post(inL,i,preL+1,preL+1+i-inL);
                post(i+1,inR,preL+1+i-inL,preR);
                break;
            }
        }
    }
    cout<<root;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("heritage.in","r",stdin);
        freopen("heritage.out","w",stdout);
    #endif
    cin>>in>>pre;
    post(0,in.length(),0,pre.length());
    cout<<endl;
    return 0;
}
