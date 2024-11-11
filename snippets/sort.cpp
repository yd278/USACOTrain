#include <bits/stdc++.h>

using namespace std;
vector<int> a = {4, 2, 8, 5, 7, 1};
int b[6] = {3,1,4,5,2,6};

struct Point{
    int x,y;
    bool operator< (const Point &other){
        if(x<other.x) return true;
        if(x==other.x && y < other.y) return true;
        return false;
    }
};
bool greaterInt (int a, int b){
    return a > b;
}
bool cmp(const Point &a, const Point &b){
    if(a.x < b.x) return true;
    if(a.x==b.x && a.y < b.y) return true;
    return false;
}
vector<Point> points = {{1,2},{2,3},{1,3},{3,4}};
int main() {
    freopen("sort.out", "w", stdout);
    // your code below
    sort(a.begin(),a.end(),greaterInt); // a.begin() reference of first element of a, a.end() 


    
    sort(points.begin(),points.end());

    // your code above
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
}