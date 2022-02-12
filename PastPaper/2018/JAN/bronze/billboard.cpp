#include <iostream>
using namespace std;
int x1, y1, x2, y2;
int x3, y3, x4, y4;
int within(int x, int y) {
    if(x<=x4 && x >= x3){
        if(y<=y4 && y >= y3)
        return 1;
    }
    return 0;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
#endif
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int cnt=0;
    cnt+= within(x1,y1);
    cnt+= within(x1,y2);
    cnt+= within(x2,y1);
    cnt+= within(x2,y2);

    if(cnt==4) cout<<0<<endl;
    if(cnt<=1) cout<<(x2-x1)*(y2-y1)<<endl;
    int ans;
    if(cnt==2){
        //vertical
        if(y1>=y3&&y2<=y4){
            if(x1>=x3) //left
                ans = (y2-y1)*(x2-x4);
            else //right
                ans = (y2-y1)*(x3-x1);
        }
        else{ //horizental
            if(y1>=y3)//low
                ans= (x2-x1)*(y2-y4);
            else
                ans=(x2-x1)*(y3-y1);
        }  
        cout<<ans<<endl; 
    }
    return 0;
}