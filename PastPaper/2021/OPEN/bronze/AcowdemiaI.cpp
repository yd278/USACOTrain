#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("AcowdemiaI.in","r",stdin);
        freopen("AcowdemiaI.out","w",stdout);
    #endif
 int N,L,h;
    cin>>N>>L;

    vector<int> paper(N+1);
    for(int i=1;i<=N;i++){
        cin>>paper[i];
    }
    paper[0] = INT_MAX;
    sort(paper.begin(),paper.end(),cmp); 
    for(int i=1;i<=N;i++){
        if(paper[i]<i){
            h=i-1;
            break;
        }
    }
    int cnt = 0;
    for(int i=1;i<=h;i++){
        if(paper[i]==h){
            cnt++;
        }
    }
    if(paper[h+1]==h&&cnt<L){
        h++;
    }
    
    cout<<h<<endl;
    return 0;

}
