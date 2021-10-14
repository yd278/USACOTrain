/*
ID: dyh2191
LANG: C++14
TASK: ratios
*/
#include <iostream>
using namespace std;
int goal[3];
int mixtures[3][3];
int sum[3];
int main() {
#ifndef ONLINE_JUDGE
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
#endif
    for (int i = 0; i < 3; i++) {
        cin >> goal[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mixtures[i][j];
        }
    }
    for (int total = 1; total <= 297; total++) {
        for (int a = 0; a < 100; a++) {
            for (int b = 0; b < 100; b++) {
                int flag = 1;
                int c = total - a - b;
                for (int i = 0; i < 3; i++) {
                    sum[i] = mixtures[0][i] * a + mixtures[1][i] * b +
                             mixtures[2][i] * c;
                    if (goal[i] == 0) {
                        if (sum[i] == 0)
                            continue;
                        else {
                            flag = 0;
                            break;
                        }
                    }
                    if (sum[i] % goal[i] != 0) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) continue;
                int t;
                for (int i = 0; i < 3; i++) {
                    if (goal[i] != 0) {
                        t = sum[i] / goal[i];
                        break;
                    }
                }
                for (int i = 0; i < 3; i++) {
                    if (goal[i] == 0) {
                        if (sum[i] == 0)
                            continue;
                        else {
                            flag = 0;
                            break;
                        }
                    } else {
                        if (sum[i] / goal[i] != t) {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag) {
                    cout << a << " " << b << " " << c << " " << t << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NONE" << endl;
}