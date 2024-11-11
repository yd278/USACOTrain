#include <bits/stdc++.h>
using namespace std;
vector<long long> as = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

long long power(long long x, long long n, long long p){ //x^n % p
    if(n==0) return 1;
    long long tmp = power(x,n/2,p);
    tmp *= tmp;
    if(tmp >= p) tmp %= p;
    if(n%2==1){
        tmp *= x;
        if(tmp >= p) tmp %= p;
    }
    return tmp;
}

bool check(long long x, long long a) {
    long long u = x-1;
    while(u%2==0) u/=2;

    long long v = power(a,u,x);
    if(v==1 || v == x-1) return true;

    while(true){
        u*=2;
        if(u==x-1) return false;
        v *= v;
        if(v>=x) v%=x;
        if(v==1) return false;
        if(v==x-1) return true;
    }
    return true;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("millerRabin.in", "r", stdin);
    freopen("millerRabin.out", "w", stdout);
#endif
    long long x;
    cin >> x;
    if (x == 1) {
        cout << "not prime" << endl;
        return 0;
    }
    if (x == 2) {
        cout << "prime" << endl;
        return 0;
    }
    if (x % 2 == 0) {
        cout << "not prime" << endl;
        return 0;
    }
    for (auto a : as) {
        if (!check(x, a)) {
            cout << "not prime" << endl;
            return 0;
        }
    }
    cout << "prime" << endl;

    return 0;
}
