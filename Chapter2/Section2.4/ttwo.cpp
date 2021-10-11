/*
ID: dyh2191
LANG: C++14
TASK: ttwo
*/

#include <iostream>
using namespace std;

int map[10][10];
int visited[400][400];
struct racer{
    int x,y;
    int dx,dy;
    int encode(){
        int dire = (dx+dy)>0;
        if(dx==0) dire+=2;
        return dire*100+x*10+y;
    }
    void rotate(){
        int tmp = dy;
        dy = -dx;
        dx = tmp;
    }
    int valid(int x){
        if(x<0)return 0;
        if(x>=10)return 0;
        return 1;
    }
    void move(){
        int tx = x+dx;
        int ty = y+dy;
        if(valid(tx)&&valid(ty)){
            if(!map[tx][ty]){
                x = tx;
                y = ty;
                return;
            }
        }
        rotate();

    }
};

racer FJ;
racer cows;
int meet(){
    return (FJ.x==cows.x) && (FJ.y==cows.y);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("ttwo.in","r",stdin);
        freopen("ttwo.out","w",stdout);
    #endif
    string line;
    char c;
    for(int i = 0; i < 10; i++){
        cin>>line;
        for(int j = 0; j < 10; j++){
            c = line[j];
            if(c=='*')map[i][j]=1;
            if(c=='F'){
                FJ = racer{i,j,-1,0};
            }
            if(c=='C'){
                cows = racer{i,j,-1,0};
            }
        }
    }
    int cnt = 0;
    while(!meet()){
        int FJe = FJ.encode();
        int cowse = cows.encode();
        if(visited[FJe][cowse]){
            cout<<0<<endl;
            return 0;
        }
        visited[FJe][cowse] = 1;
        FJ.move();
        cows.move();
        cnt ++;
    }
    cout<<cnt<<endl;
    
}