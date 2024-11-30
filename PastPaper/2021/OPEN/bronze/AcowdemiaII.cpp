#include<bits/stdc++.h>
using namespace std;

int order[100][100];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("AcowdemiaII.in","r",stdin);
        freopen("AcowdemiaII.out","w",stdout);
    #endif
    map<string,int> dict;

    int n,k;
    cin>>k>>n;
    vector<string> names(n);
    vector<string> paper(n);
    for(int i = 0; i < n; i++){
        cin>>names[i];
        dict[names[i]] = i;
    }
    for(int i = 0; i < k; i++){
        for(int j =0; j < n; j++){
            cin>>paper[j];
        }
        for(int j = 0; j <n-1; j++){
            if(paper[j]>paper[j+1]){
                for(int x = 0; x <= j; x++){
                    for(int y = j+1; y < n; y++){
                        int ix = dict[paper[x]];
                        int iy = dict[paper[y]];
                        order[iy][ix] = 1;
                    }   
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j)cout<<'B';
            else{
                if(order[i][j]==0 && order[j][i] == 0)cout<<'?';
                else cout<<order[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}
