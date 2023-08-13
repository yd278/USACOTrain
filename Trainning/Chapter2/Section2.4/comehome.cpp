/*
ID: dyh2191
LANG: C++14
TASK: comehome
*/
#include <iostream>
using namespace std;

int dist[52][52];
int handle(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 26;
    } else {
        return c - 'A';
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("comehome.in","r",stdin);
        freopen("comehome.out","w",stdout);
    #endif
    int n;
    cin >> n;
    char a, b;
    int d;
    for (int i = 0; i < 52; i++) {
        for (int j = i + 1; j < 52; j++) {
            dist[i][j] = dist[j][i] = 1073741823;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> d;
        int ia = handle(a);
        int ib = handle(b);
        if (dist[ia][ib] > d) {
            dist[ia][ib] = dist[ib][ia]=d;
        }
    }
    for (int k = 0; k < 52; k++) {
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int res = INT_MAX;
    int index = 0;
    for(int i = 0; i < 25;i++){

            if(dist[i][25]<res){
                res=dist[i][25];
                index =i;
            }
        }
    
    cout<<(char)(index+'A')<<" "<<res<<endl;
}