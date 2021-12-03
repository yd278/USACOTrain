#include <iostream>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char map[5][5];
int visited[5][5];
int ans;
int n;
int check(int xx, int yy){
    if(visited[xx][yy])return 0;
    if(xx>=0 && xx < n){
        if(yy>=0 && yy < n){
            return 1;
        }
    }
    return 0;
}
void dfs(int x, int y, int count, int depth, int direction){ //success return 1, unsuccess return 0;
    if(count == 0 && direction == -1){
        if(depth>ans)ans = depth;
    }
    visited[x][y] = 1;
    for( int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(check(xx,yy)){
            char next = map[xx][yy];
            if(direction == -1){
                if(next == '(') continue;
                dfs(xx,yy,count-1,depth+1,-1);
            }else{
                if(next=='(') dfs(xx,yy,count+1,depth+1,1);
                else dfs(xx,yy,count-1, depth+1, -1);
            }
        }
    }
    visited[x][y] = 0;
 
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("hshoe.in","r",stdin);
        freopen("hshoe.out","w",stdout);
    #endif
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>map[i][j];
        }
    }
    if(map[0][0]==')'){
        cout<<0<<endl;
        return 0;
    }
    dfs(0,0,1,1,1);
    cout<<ans<<endl;
}