#include <iostream>
#include <queue>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("1090.in","r",stdin);
        freopen("1090.out","w",stdout);
    #endif
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    int a,b;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a;
        q.push(a);
    }
    int sum = 0;
    while(q.size()>1){
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        sum+=a+b;
        q.push(a+b);
    }

    cout<<sum<<endl;
}