#include <bits/stdc++.h>
using namespace std;

vector<int> bales;

int main() {
#ifndef ONLINE_JUDGE
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    bales.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> bales[i];
    }
    bales[n] = INT_MAX;
    sort(bales.begin(), bales.end());

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        // lowerbound
        int lower;
        int l = 0;
        int r = n;
        while (l != r) {
            int mid = (l + r) / 2;
            if (bales[mid] >= a)
                r = mid;
            else
                l = mid + 1;
        }
        lower = l;

        // upperbound
        int upper;
        l = 0;
        r = n;
        while (l != r) {
            int mid = (l + r) / 2;
            if (bales[mid] > b)
                r = mid;
            else
                l = mid + 1;
        }
        upper = l;
        cout << upper - lower << endl;
    }
    return 0;
}