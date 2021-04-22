/*
ID: dyh2191
LANG: C++14
TASK: skidesign
*/

#include <iostream>
using namespace std;

int height[1001];
int n;
int cost(int x) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a = height[i];
        if (a < x) res += (x - a) * (x - a);
        if (a > x + 17) res += (a - x - 17) * (a - x - 17);
    }
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
#endif

    cin >> n;
    int Min = 1001;
    int Max = 0;
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        if (height[i] > Max) Max = height[i];
        if (height[i] < Min) Min = height[i];
    }
    int lowcost = 999999999;
    for (int i = Min; i < Max; i++) {
        int tmp = cost(i);
        if (tmp < lowcost) lowcost = tmp;
    }
    cout << lowcost << endl;
}
