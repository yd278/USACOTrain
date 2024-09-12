#include<bits/stdc++.h>
using namespace std;
struct Cow{
    int w,x,d;
    bool operator< (const Cow &other) const{
        return x < other.x;
    }
};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("meetings.in","r",stdin);
        freopen("meetings.out","w",stdout);
    #endif
    int n,l;
    cin>>n>>l;
    int sum = 0;
    vector<Cow> cows(n);
    for(auto &cow :cows){
        cin>>cow.w>>cow.x>>cow.d;
        sum += cow.w;
    }

    sort(cows.begin(),cows.end());
    vector<int> tLeft, tRight;
    for(auto [w,x,d] : cows){
        if(d==-1) tLeft.push_back(x);
        else tRight.push_back(l-x);
    }
    int arrive = 0;
    int pL = 0;
    int pR = tRight.size() - 1;
    int wL = 0;
    int wR = n - 1;
    int T;
    while((arrive<<1) < sum){
        if(pL<tLeft.size() && (pR<0 || tLeft[pL] < tRight[pR])) {
            arrive += cows[wL].w;
            T = tLeft[pL];
            pL++;
            wL++;
        }
        else if(pR>=0 &&(pL>= tLeft.size() || tLeft[pL] >= tRight[pR])){
            arrive+= cows[wR].w;
            T = tRight[pR];
            pR--;
            wR--;
        }

    }
    
    vector<int> cnt(n+1);
    for(int i = 1; i <= n; i++){
        cnt[i] = cnt[i-1] + (cows[i-1].d==-1);
    }
    
    int winR = 0;
    int ans = 0;
    for(int winL= 0; winL <n; winL ++){
        if(cows[winL].d != 1) continue;
        while(winR<n && cows[winR].x <= cows[winL].x + 2 * T) winR ++;
        
        ans += cnt[winR] - cnt[winL];
    }
    cout<<ans<<endl;
    return 0;
}
