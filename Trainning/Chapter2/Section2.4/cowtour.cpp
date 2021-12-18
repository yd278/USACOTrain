/*
ID: dyh2191
LANG: C++14
TASK: cowtour
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int n;
int x[150];
int y[150];
double dist[150][150];
double diameter[150];
int lable[150];
double farthest[150];
inline double d(int i, int j){
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return sqrt(dx*dx+dy*dy);
}
void floodfill(int x,int l){
    lable[x] = l;
    for(int i = 0; i < n; i++){
        if(lable[i]==0&&dist[x][i]<89999999){
            floodfill(i,l);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("cowtour.in","r",stdin);
        freopen("cowtour.out","w",stdout);
    #endif
    double result = 99999999;
    //input
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i];
    }
    string line;
    for(int i = 0; i < n; i++){
        cin>>line;
        for(int j = 0; j < n; j++){
            if(line[j]=='0'){
                dist[i][j] = 99999999;
            }else{
                dist[i][j] = d(i,j);
            }
        }
    }
    for(int i = 0; i < n; i++)dist[i][i] = 0;
    //floyd
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    //asign lable to each point
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(lable[i]==0){
            floodfill(i,cnt);
            cnt++;
        }
    }
    //find farthest point for each point
    for(int i = 0; i < n; i++){
        double Max = 0;
        for(int j = 0; j < n; j++){
            if(dist[i][j]<89999999 && dist[i][j] > Max){
                Max = dist[i][j];
            }
        }
        farthest[i] = Max;
        if(diameter[lable[i]]<Max){
            diameter[lable[i]]=Max;
        }
    }
    //iterating pairs
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(lable[i]!=lable[j]){
                double dist = farthest[i] + farthest[j] + d(i,j);
                dist = max(dist,diameter[lable[i]]);
                dist = max(dist,diameter[lable[j]]);
                result = min(dist, result);
            }
        }
    }
    cout<<fixed<<setprecision(6)<< result<<endl;
    
}