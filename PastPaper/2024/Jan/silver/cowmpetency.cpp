#include <bits/stdc++.h>

using namespace std;

void process() {
    int n, q, C;
    cin >> n >> q >> C;
    int a, h;
    vector<int> label(n + 1);  // -1: npm, 1: pm, 0: no restrict
    vector<int> minA(n + 1, INT_MAX);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 0; i < q; i++) {
        cin >> a >> h;
        label[h] = 1;
        minA[h] = min(minA[h], a + 1);
    }
    int state = 0;
    for (int i = n; i >= 1; i--) {
        if (state) {
            if (label[i] == 1) {
                cout << -1 << endl;
                return;
            }
            label[i] = -1;
        } else {
            if (label[i] == 1) state = minA[i];
        }
        if (i == state) state = 0;
    }
    int last = 0;
    int preMax = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i]) {
            if (label[i] == -1) {
                if (c[i] > preMax) {
                    if (last)
                        c[last] = c[i];
                    else {
                        cout << -1 << endl;
                        return;
                    }
                }
            }
        } else {
            if (label[i] == -1) c[i] = 1;
            if (label[i] == 0) {
                c[i] = 1;
                last = i;
            }
            if (label[i] == 1) {
                c[i] = preMax + 1;
                last = i;
            }
        }
        preMax = max(preMax, c[i]);
    }

    preMax = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] > C) {
            cout << -1 << endl;
            return;
        }
        if (label[i] == -1 && c[i] > preMax) {
            cout << -1 << endl;
            return;
        }
        if (label[i] == 1 && c[i] <= preMax) {
            cout << -1 << endl;
            return;
        }
        preMax = max(preMax,c[i]);
    }
    for (int i = 1; i <= n-1; i++) {
        cout << c[i] << " ";
    }
    cout<<c[n]<<endl;
}
int main() {

    int t;
    cin >> t;
    while (t--) {
        process();
    }

    return 0;
}
