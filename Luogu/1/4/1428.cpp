#include <iostream>
#include <vector>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("1428.in","r",stdin);
        freopen("1428.out","w",stdout);
    #endif
    vector<int> cuteness;
    int num;
    cin>>num;
    int t;
    for(int i = 0; i < num; i++){
        cin>>t;
        cuteness.push_back(t);
    }
    int cnt;
    vector<int> res;
    for(int i = 0; i < num; i++){
        cnt = 0;
        for(int j = 0; j < i; j++){
            if(cuteness[i] > cuteness[j])cnt++;
        }
        res.push_back(cnt);
    }
    for(auto x : res){
        cout<<x<<" ";
    }

}