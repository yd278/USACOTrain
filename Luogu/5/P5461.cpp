#include <iostream>
using namespace std;

int a[1024][1024];

void charge(int i,int j, int size){
    if(size == 1){
        a[i][j] = 1;
        return;
    }
    int tmp = size / 2;
    charge(i+tmp,j,tmp);
    charge(i,j+tmp,tmp);
    charge(i+tmp,j+tmp,tmp);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("P5461.in","r",stdin);
        freopen("P5461.out","w",stdout);
    #endif
    int n;
    cin>>n;
    int size = 1 << n;
    charge(0,0,size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<a[i][size - 1]<<endl;
    }
    return 0;
}