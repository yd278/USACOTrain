#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
struct Point {
    int x, y;
    int index;
};
inline const bool cmpUp(const Point &a, const Point &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

inline const bool cmpLeft(const Point &a, const Point &b) {
    return a.y == b.y ? a.x < b.x : a.y < b.y;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].index = i;
    }

    vector<long long> sUp(n);
    vector<long long> sDown(n);
    vector<long long> sLeft(n);
    vector<long long> sRight(n);

    sort(points.begin(), points.end(), cmpUp);
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x == points[i - 1].x) {
            cnt++;
            sUp[points[i].index] += sUp[points[i-1].index]+(points[i].y - points[i-1].y)*cnt;
            sUp[points[i].index] %= MOD;
        }
        else cnt = 0;
    }
    cnt = 0;
    for(int i = n - 2; i >= 0; i--){
        if (points[i].x == points[i+1].x){
            cnt++;
            sDown[points[i].index] += sDown[points[i+1].index] + (points[i+1].y - points[i].y)*cnt;
            sDown[points[i].index] %= MOD;
        }
        else cnt = 0;
    }
    sort(points.begin(), points.end(), cmpLeft);
    cnt = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y == points[i - 1].y) {
            cnt++;
            sLeft[points[i].index] += sLeft[points[i-1].index] + (points[i].x - points[i-1].x)*cnt;
            sLeft[points[i].index] %= MOD;
        }
        else cnt = 0;
    }
    cnt = 0;
    for(int i = n - 2; i >= 0; i--){
        if (points[i].y == points[i+1].y){
            cnt++;
            sRight[points[i].index] +=sRight[points[i+1].index] + (points[i+1].x - points[i].x)*cnt;
            sRight[points[i].index] %= MOD;
        }
        else cnt = 0;
    }

    long long res = 0;
    for(int i = 0; i < n;  i++){
        res += (sRight[i] + sLeft[i]) * (sUp[i] + sDown[i]);
        res %= MOD;
    }
    cout<<res<<endl;
}