#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int l[100];
int r[100];
struct Time{
    int t;
    int start;
    bool operator<(const Time &other)const{
        return t<other.t;
    }
};

int count(vector<Time> times){
    sort(times.begin(),times.end());
    int res = 0;
    int cnt = 0;
    int prev = 0;
    for(auto x:times){
        if(x.start){
            cnt++;
            if(cnt==1)prev = x.t;
        }else{
            cnt--;
            if(cnt==0)res += x.t-prev;
        }
    }
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("lifeguards.in","r",stdin);
        freopen("lifeguards.out","w",stdout);
    #endif
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>l[i]>>r[i];
    }
    int maxAns = 0;
    for(int i = 0; i < n; i++){
        vector<Time> tmp;
        for(int j = 0; j < n; j++){
            if(j!=i){
                tmp.push_back(Time{l[j],1});
                tmp.push_back(Time{r[j],0});
            }
        }
        int ans = count(tmp);
        if(maxAns < ans) maxAns = ans;
    }
    cout<<maxAns<<endl;    
}