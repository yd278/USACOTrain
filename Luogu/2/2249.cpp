#include <iostream>
using namespace std;

int a[1000000];
int n, m;
int find(int x) {
    int l = 0;
    int r = n - 1;
    while (l != r) {
        int mid = (l + r) / 2;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    if (a[l] == x)
        return l + 1;
    else
        return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("2249.in", "r", stdin);
    freopen("2249.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    for (int i = 0; i < m; i++) {
        cin >> k;
        cout << find(k) << " ";
    }
    return 0;
}