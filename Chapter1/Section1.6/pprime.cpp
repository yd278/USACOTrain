/*
ID: dyh2191
LANG: C++14
TASK: pprime
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int store[10];              //存储回文数的位置，store[0]为外侧
int decode(int n, int x) {  //生成2n-1位的回文数
    int res = 0;
    int t = x;
    for (int i = 0; i < n - 1; i++) {
        res = res * 10 + (t % 10);
        t /= 10;
    }
    for (int i = 0; i < n; i++) res *= 10;
    res += x;

    return res;
}
int prime(int x) {  // x>=101
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
vector<int> ans;
int main() {
#ifndef ONLINE_JUDGE
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    if (a <= 5) ans.push_back(5);
    if (a <= 7) ans.push_back(7);
    if (a <= 11) ans.push_back(11);
    int x;
    for (int i = 1; i < 10000; i++) {

        if (i % 10 == 0) continue;
        if (i < 100) {
            x = decode(2, i);
            if (a <= x && x <= b)
                if (prime(x)) ans.push_back(x);
        }
        if (i < 1000) {
            x = decode(3, i);
            if (a <= x && x <= b)
                if (prime(x)) ans.push_back(x);
        }
        x = decode(4, i);
        if (a <= x && x <= b)
            if (prime(x)) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << endl;
    }
    return 0;
}