#include <bits/stdc++.h>

vector<int> a; //size = 0
struct Pos{
    int x,y;
    bool operator< (Pos &other){
        if(x <other.x) return true;
        if(x==other.x && y < other.y) return true;
        return false;
    }
};
bool cmp(Pos &a, Pos &b){
    if(a.x < b.x) return true;
    if(a.x == b.x && a.y < b.y) return true;
    return false;
}
int arr[5];
vector<Pos> positions;
int main(){

    a.push_back(1); 
    a.push_back(2);
    a.push_back(3);

    int c = a[2]; // c = 3;
    a[1] = c + 2; // a= {1,5,3};
    positions.resize(10);
  
    sort(positions.begin(),positions.end());

    Pos pa;
    Pos pb;
    if(pa<pb){

    }

    int front = a.front(); // 1;
    int back = a.back(); // 3;
    front = a[0];
    int len = a.size();
    back = a[a.size()-1];

    vector<int> b(3); //b = {0,0,0}
    vector<int> bs(3,4); // {4,4,4}
    int n = 5;

    a.resize(2); // a= {1,5}
    a.resize(3,5); // a {5,5,5}
    cin>>n;
    a.resize(n); // a = {5,5,5,0,0}
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for( int x : a){ //逐个取出来赋值给x （复制给x）
        cout<<x<<endl;
    }
    for( int x : a){ //这么写不会影响到a
        cin>>x;
    }

    //引用 reference
    for(int &x : a){ // 这么写会影响到a， 此时x只是a[0]的另一个名字
        cin>>x;
    }

    vector< vector<int> > grid(5); // 5 行 0 列
    vector <vector<int>> gird2(5,vector<int>(8));
    for(int i = 0; i < 5; i++){
        grid[i].resize(8);
    }

    sort(a.begin(),a.end());
    sort(&arr[0],&arr[5]);
    sort(arr,arr+5);

}