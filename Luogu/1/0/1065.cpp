#include <bits/stdc++.h>
using namespace std;

int order[400];
int mach[20][20];
int cost[20][20];
int step[20];
int last[20];
int timeline[20][10000];

void check(int x, int m, int t){
    int scan = last[x];
    while(1){
        int flag = 0;
        for(int i = 0; i < t; i++){
            if(timeline[m][i+scan]!=0){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            for(int i = 0; i < t; i++){
                timeline[m][i+scan] = 1;

            }
            last[x] = scan + t;
            break;
        }
        scan++;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("1065.in","r",stdin);
        freopen("1065.out","w",stdout);
    #endif
    int n,m;
    cin>>m>>n;
    for(int i = 0; i < m * n; i++){
        cin>>order[i];
        order[i]--;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mach[i][j];
            mach[i][j]--;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>cost[i][j];
        }
    }

    for(int i = 0; i<n*m;i++){
        int c_step = step[order[i]]++;
        int c_mach = mach[order[i]][c_step];
        int c_cost = cost[order[i]][c_step];
        check(order[i],c_mach,c_cost);
    }
    int latest = 0;
    for(int i = 0; i < n; i++){
        if( last[i] >latest) latest = last[i];
    }

    cout<<latest<<endl;
    return 0;
    
}