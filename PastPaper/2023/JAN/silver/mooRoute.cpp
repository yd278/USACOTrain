#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int leftmost = 0;
    int rightmost = n;
    int cur = 0;
    int direction = 1;
    while (leftmost != rightmost) {
        if (cur == rightmost) {
            direction = 0;
            cout << 'L';
            a[cur - 1]--;
            if (a[cur - 1] == 0) rightmost--;
            cur--;
            continue;
        }
        if (cur == leftmost) {
            direction = 1;
            cout << 'R';
            a[cur]--;
            if (a[cur] == 0) leftmost++;
            cur++;
            continue;
        }
        if (direction) {
            if (a[cur] == 1) {
                if (leftmost != cur) {
                    direction = 0;
                    continue;
                } else {
                    leftmost++;
                }
            }
            cout << 'R';
            a[cur]--;
            cur++;

        } else {
            if (a[cur - 1] == 1) {
                if (rightmost != cur) {
                    direction = 1;
                    continue;
                } else {
                    rightmost--;
                }
            }
            cout << 'L';
            a[cur - 1]--;
            cur--;
        }
    }
    return 0;
}
