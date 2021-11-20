#include <iostream>
using namespace std;

void check(int n, string record) {
    int i = 0;
    int w = 0;
    int l = 0;
    while (1) {
        if (record[i] == 'E') {
            cout << w << ":" << l << endl;
            return;
        }
        if (record[i] == 'W') {
            w++;
            if (w >= n && w - l >= 2) {
                cout << w << ":" << l << endl;
                w = 0;
                l = 0;
            }
        }
        if (record[i] == 'L') {
            l++;
            if (l >= n && l - w >= 2) {
                cout << w << ":" << l << endl;
                w = 0;
                l = 0;
            }
        }
        i++;
    }
}
int main() {
    string line;
    string record;
#ifndef ONLINE_JUDGE
    freopen("tennis.in", "r", stdin);
    freopen("tennis.out", "w", stdout);
#endif
    // for (record = ""; cin >> line; record += line);
    record = "";
    while (cin >> line) {
        record += line;
    }

    check(11, record);
    cout << endl;
    check(21, record);
    return 0;
}