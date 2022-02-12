#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct patch{
    int pos;
    long long taste;
    const bool operator< (patch &other) const{
        return pos < other.pos;
    }
}patches[200000];
int k,m,n;
int woc[200000];
vector <long long> values;
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("closest.in","r",stdin);
    //     freopen("closest.out","w",stdout);
    // #endif
    cin>>k>>m>>n;
    for(int i = 0; i < k; i++){
        cin>>patches[i].pos>>patches[i].taste;
    }
    for(int i = 0; i < m; i++){
        cin>>woc[i];
    }
    sort(woc, woc+ m);
    sort(patches,patches+k);
    
    int wocI = 0;
    int pI = 0;
    long long value = 0;
    while(patches[pI].pos<woc[wocI]){
        value += patches[pI].taste;
        pI++;
    
    }
    values.push_back(value);

    while(wocI<m-1){
        long long sum = 0;
        long long half = 0;
        long long maxHalf = 0;
        int gap = woc[wocI+1] - woc[wocI];
        double window = gap / 2.0;
        while(patches[pI].pos<=woc[wocI])pI++;
        for(int pJ = pI; patches[pJ].pos < woc[wocI+1];pJ++){
            sum+=patches[pJ].taste;
            half+= patches[pJ].taste;
            while(patches[pJ].pos - patches[pI].pos >= window){
                half -= patches[pI].taste;
                pI++;
            }
            if(half > maxHalf) maxHalf = half;
        }
        values.push_back(maxHalf);
        values.push_back(sum-maxHalf);
        wocI++;
    }

    while(patches[pI].pos <= woc[m-1]) pI++;
    value = 0;
    while(pI < k){
        value += patches[pI].taste;
        pI++;
    }
    values.push_back(value);

    sort(values.begin(),values.end(),greater<>());
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans+=values[i];
    }
    cout<<ans<<endl;

    
}


