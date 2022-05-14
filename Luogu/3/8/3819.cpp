#include <bits/stdc++.h>
using namespace std;
struct house{
    long long loc;
    long long r;
    bool operator< (const house &other) const{
        return loc < other.loc;
    }
};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("3819.in","r",stdin);
        freopen("3819.out","w",stdout);
    #endif
    vector<house> houses;
    long long L,N;
    cin>>L>>N;
    for(int i = 0; i < N; i++){
        long long a,b;
        cin>>a>>b;
        houses.push_back(house{a,b});
    }

    sort(houses.begin(),houses.end());
    int l = 0;
    int r = houses.size() - 1;
    long long ans = 0;
    while(l!=r){
        #define hl houses[l]
        #define hr houses[r]

        if(hl.r < hr.r){
            ans += (long long)(hr.loc - hl.loc) * hl.r;
            hr.r -= hl.r;
            l++;
        }else{
            
            ans += (long long)(hr.loc - hl.loc) * hr.r;
            hl.r -= hr.r;
            r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}