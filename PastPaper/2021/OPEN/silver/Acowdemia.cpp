#include <bits/stdc++.h>
using namespace std;

int n, k, l;
bool check(vector<int> c, int h) {
    int i;
    for (i = 0; i < n; i++) {
        if (c[i] < h) break;
    }
    if (i >= h) return true;
    long long total = (long long)k * l;
    while (i < h) {
        if (c[i] + k < h) return false;
        if (total >= h - c[i]) {
            total -= h - c[i];
            i++;
        } else
            return false;
    }
    return true;
}
int main() {

    cin >> n >> k >> l;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end(), greater<int>());

    int l = 0;
    int r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(c, mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (check(c, r))
        cout << r << endl;
    else
        cout << l << endl;
}