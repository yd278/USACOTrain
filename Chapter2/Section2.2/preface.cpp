/*
ID: dyh2191
LANG: C++14
TASK: preface
*/
#include <iostream>
using namespace std;
int sum[9];
char ch[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int one[10] = {0, 1, 2, 3, 1, 0, 1, 2, 3, 1};
int five[10] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
int ten[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

int main() {
#ifndef ONLINE_JUDGE
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
#endif
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int t = i;
        int shift = 0;
        while (t) {
            int p = t % 10;
            sum[shift] += one[p];
            sum[shift + 1] += five[p];
            sum[shift + 2] += ten[p];
            t /= 10;
            shift += 2;
        }
    }
    for (int i = 0; i < 7; i++) {
        if (sum[i]) cout << ch[i] << " " << sum[i] << endl;
    }
}