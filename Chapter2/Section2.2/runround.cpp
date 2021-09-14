/*
ID: dyh2191
LANG: C++14
TASK: runround
*/

#include <iostream>
using namespace std;
int num[9];
int length;
int Max[7] = {9, 97, 852, 9627, 97842, 974835, 9682415};
int Min[7] = {1, 13, 147, 1263, 12368, 134259, 1246895};
int Next[9][10];

void convert(int n) {
    int i = 0;
    while (n) {
        num[i] = n % 10;
        n /= 10;
        i++;
    }
    length = i;
}
void succ() {
    num[0]++;
    int i = 0;
    while (num[i] >= 10) {
        num[i] %= 10;
        num[i + 1]++;
        i++;
    }
}
int check() {
    int used[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < length; i++) {
        if (used[num[i]]) return 0;
        used[num[i]] = 1;
    }
    return 1;
}

int runRound() {
    int used[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int current = 0;
    for (int i = 0; i < length; i++) {
        if (used[current]) return 0;
        used[current] = 1;
        current = Next[current][num[current]];
    }
    return current == 0;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
#endif
    int n;
    cin >> n;
    convert(n);
    if (n >= Max[length - 1]) {
        cout << Min[length] << endl;
        return 0;
    }
    for (int i = 1; i < length; i++) {
        Next[i][0] = i;
        Next[i][1] = i - 1;
    }
    Next[0][0] = 0;
    Next[0][1] = length - 1;

    for (int j = 2; j <= 9; j++) {
        for (int i = 0; i < length; i++) {
            Next[i][j] = Next[Next[i][j - 1]][1];
        }
    }

    succ();
    while (1) {
        if (check()) {
            if (runRound()) {
                for (int i = length - 1; i >= 0; i--) {
                    cout << num[i];
                }
                cout << endl;
                return 0;
            }
        }
        succ();
    }
}