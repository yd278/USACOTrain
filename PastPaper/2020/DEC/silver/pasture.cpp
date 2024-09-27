#include <bits/stdc++.h>
using namespace std;
struct Cow {
    int x, y;
};
bool cmpX(const Cow &x, const Cow &y) { return x.x < y.x; }
bool cmpY(const Cow &x, const Cow &y) { return x.y < y.y; }
inline int count(int x1, int y1, int x2, int y2, vector<vector<int>> &cnt){
    x1--;
    y1--;
    return cnt[x2][y2] - cnt[x1][y2] - cnt[x2][y1] + cnt[x1][y1];
}
int main() {

    int n;
    cin >> n;
    vector<Cow> cows(n);
    for (auto &cow : cows) {
        cin >> cow.x >> cow.y;
    }
    sort(cows.begin(), cows.end(), cmpY);
    for (int i = 0; i < n; i++) {
        cows[i].y = i+1;
    }
    sort(cows.begin(), cows.end(), cmpX);
    for (int i = 0; i < n; i++) {
        cows[i].x = i+1;
    }
    vector<vector<int>> cnt(n+1,vector<int>(n+1));
    for(auto [x,y] :cows){
        cnt[x][y] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1] + cnt[i][j];
        }
    }

    long long sum = 0;
    for(int i = 1; i<= n-1; i++){
        for(int j = i+1; j <= n; j++){
            int yi = cows[i-1].y;
            int yj = cows[j-1].y;
            if(yi < yj) swap(yi,yj);
            long long up = count(i+1,1,j-1,yj-1,cnt);
            long long down = count(i+1,yi+1,j-1,n,cnt);
            sum += (up+1) * (down+1);
            
        }
    }
    cout<<sum+1+n<<endl;


    return 0;
}
