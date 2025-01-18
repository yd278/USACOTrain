#include <bits/stdc++.h>

int state;

void swap(int &x, int &y){
    int t = x;
    x = y;
    y = t;
}


int pow(int x, int y){
    if (state == 1){
        int res = 1;
        for(int i = 0; i < y; i++){
            res *= x;
        }
        return res;
    }
    else{
        int res = 1;
        for( int i = 0; i < x; i++){
            res *= y;
        }
        return res;
    }
}


int main(){
    state = 1;
    cout<<pow(3,5);
    state = 0;
    cout<<pow(3,5);
    int a = 3;
    int b = 5;
    swap(a,b);
    
    return 0;
}