/*
ID: dyh2191
LANG: C++14
TASK: humble
*/
#include <vector>
#include <iostream> 
using namespace std;

vector<int> humble;
int k,n;
int prime[100];
int tail[100];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("humble.in","r",stdin);
        freopen("humble.out","w",stdout);
    #endif
    cin>>k>>n;
    for(int i = 0; i < k; i++){
        cin>>prime[i];
    }
    humble.push_back(1);
    for(int i = 0; i < n; i++){
        int Min = 2147483647;
        for(int j = 0; j < k; j++){
            while(humble[tail[j]]*prime[j]<=humble.back()){
                tail[j]++;
            }
            if(humble[tail[j]]*prime[j]<Min){
                Min = humble[tail[j]]*prime[j];
            }
        }
        humble.push_back(Min);
    }
    cout<<humble.back()<<endl;
}