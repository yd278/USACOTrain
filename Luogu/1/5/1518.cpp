#include<bits/stdc++.h>
using namespace std;

struct Pos{
    int x, y;
    int dir; // 0 up, 1 right, 2 down, 3 left
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
Pos cow;
Pos farmer;
bool grid[10][10]; //false : land, true obst

void move(){
    int nx,ny;
    nx = cow.x + dx[cow.dir];
    ny = cow.y + dy[cow.dir];
    if(nx<0 || nx>=10 || ny < 0 || ny >= 10 || grid[nx][ny]) {
        cow.dir+=1;
        if(cow.dir==4) cow.dir = 0;
    }else{
        cow.x = nx;
        cow.y = ny;
    }

    nx = farmer.x + dx[farmer.dir];
    ny = farmer.y + dy[farmer.dir];
    if(nx<0 || nx>=10 || ny < 0 || ny >= 10 || grid[nx][ny]) {
        farmer.dir+=1;
        if(farmer.dir==4) farmer.dir = 0;
    }else{
        farmer.x = nx;
        farmer.y = ny;
    }

}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("1518.in","r",stdin);
        freopen("1518.out","w",stdout);
    #endif

    string line;
    for(int i = 0; i < 10; i++){
        cin>>line;
        for(int j = 0; j < 10; j++){
            grid[i][j] = line[j]=='*';
            if(line[j] == 'F'){
                farmer.x = i;
                farmer.y = j;
                farmer.dir = 0;
            }if(line[j] == 'C'){
                cow.x = i;
                cow.y = j;
                cow.dir = 0;
            }
        }
    }
    for(int i = 0; i <= 40000; i++){
        
        if(farmer.x == cow.x && farmer.y==cow.y){
            cout<<i<<endl;
            return 0;
        }

        move();
    }
    cout<<0<<endl;

    return 0;
}
