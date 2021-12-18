/*
ID: dyh2191
LANG: C++14
TASK: spin
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> shift(vector<int> origin, int speed){
    vector<int> res(360);
    for(int i = 0; i < 360; i++){
        if(origin[i]){
            res[(i+speed)%360] = 1;
        }
    }
    return res;
}

vector<int> wheels[5];
int check(){
    for(int i = 0; i < 360;i++){
        int flag = 1;
        for(int j = 0; j < 5;j++){
            if(wheels[j][i]==0){
                flag = 0;
                break;
            }
        }
        if(flag) return 1;

    }
    return 0;
}
int speed[5];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("spin.in","r",stdin);
        freopen("spin.out","w",stdout);
    #endif
    for(int i = 0; i < 5; i++){
        int w;
        wheels[i].resize(360);
        cin>>speed[i]>>w;
        for(int j = 0; j < w; j++){
            int a,b;
            cin>>a>>b;
            for(int k = 0; k <= b; k++){
                wheels[i][(a+k)%360] = 1;
            }
        }
    }
    int t = 0;
    while(!check()){
        for(int i = 0; i < 5; i++){
            wheels[i] = shift(wheels[i],speed[i]);
        }
        t++;
        if(t==360){
            cout<<"none"<<endl;
            return 0;
        }
    }
    cout<<t<<endl;
    return 0;
}