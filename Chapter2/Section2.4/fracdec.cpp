/*
ID: dyh2191
LANG: C++14
TASK: fracdec
*/
#include<iostream>
using namespace std;

string res;
void print(){
    int cnt=0;
    for(auto x : res){
        cout<<x;
        cnt++;
        if(cnt==76){
            cout<<endl;
            cnt=0;
        }
    }
    cout<<endl;
}
int Prev[100000];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("fracdec.in","r",stdin);
        freopen("fracdec.out","w",stdout);
    #endif
    int n,d;
    cin>>n>>d;
    int k = n / d;
    res = to_string(k) + '.';
    int rem = n % d;
    if(rem == 0){
        res += '0';
        print();
        return 0;
    }
    int last = 0;
    Prev[rem] = res.size();
    while(rem){
        rem *= 10;
        res += to_string(rem/d);
        rem %= d;
        if(Prev[rem]){
            last = Prev[rem];
            break;
        }
        Prev[rem] = res.size();
    }
    if(last){
        res.insert(last,"(");
        res+=')';
    }
    print();
    
    return 0;
}