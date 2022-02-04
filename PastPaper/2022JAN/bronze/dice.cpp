#include <bits/stdc++.h>
using namespace std;

int better(vector<int> a, vector<int> b) {
    int win = 0;
    int loss = 0;
    for (auto x : a) {
        for (auto y : b) {
            if (x > y) win++;
            if (x < y) loss++;
        }
    }
    return win > loss;
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("dice.in", "r", stdin);
//     freopen("dice.out", "w", stdout);
// #endif
    int T;
    cin >> T;
    while (T--) {
        vector<int> a(4);
        vector<int> b(4);
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < 4; i++) {
            cin >> b[i];
        }
        vector<int> c(4);
        if (better(a, b)) {
            for (c[0] = 1; c[0] <= 10; c[0]++)
                for (c[1] = 1; c[1] <= 10; c[1]++)
                    for (c[2] = 1; c[2] <= 10; c[2]++)
                        for (c[3] = 1; c[3] <= 10; c[3]++)
                            if (better(c, a) && better(b, c)) {
                                cout << "yes\n";
                                goto start;
                            }
            cout << "no\n";

        } else if (better(b, a)) {
            for (c[0] = 1; c[0] <= 10; c[0]++)
                for (c[1] = 1; c[1] <= 10; c[1]++)
                    for (c[2] = 1; c[2] <= 10; c[2]++)
                        for (c[3] = 1; c[3] <= 10; c[3]++)
                            if (better(c, b) && better(a, c)) {
                                cout << "yes\n";
                                goto start;
                            }
            cout << "no\n";
        } else {
            cout << "no\n";
        }
    start:{}
    }
    return 0;
}