#include <bits/stdc++.h>
using namespace std;
int n;
map<string,int[25]> chars;
int check(int a[], int b[]){
    int flaga = 0;
    int flagb = 0;
    int flagi = 0;
    for(int i = 0; i < n; i++){
        if(a[i] && !b[i]) flaga = 1;
        if(!a[i] && b[i]) flagb = 1;
        if(a[i] && b[i]) flagi = 1;
    }
    return flaga&&flagb&&flagi;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("evolution.in","r",stdin);
    freopen("evolution.out","w",stdout);
#endif

    string characteristic;
    cin>>n;
    for(int i =0; i < n; i++){
        int k;
        cin>>k;
        for(int j = 0; j < k; j++){
            cin>>characteristic;
            chars[characteristic][i]=1;
        }
    }

    // for(auto charA : chars){
    //     for(auto charB : chars){
    //         if(charA.first==charB.first)continue;
    //         if(check(charA.second,charB.second)){
    //             cout<<"no"<<endl;
    //             return 0;
    //         }
    //     }
    // }

    for(auto i = chars.begin(); i != chars.end(); i++){
        for(auto j = next(i); j != chars.end(); j++){
            if(check(i->second,j->second)){
                cout<<"no"<<endl;
                return 0;
            }
        }
    }
    cout<<"yes"<<endl;
    return 0;
}