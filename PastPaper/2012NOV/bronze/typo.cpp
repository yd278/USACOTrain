#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
void rev() {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        s[i] ^= 1;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("typo.in", "r", stdin);
    freopen("typo.out", "w", stdout);
#endif
    cin >> s;
    int n = s.length();
    int cnt = 0;
    ;
    for (int i = 0; i < n; i++) {
        cnt += (s[i] & 1) ? 1 : -1;
    }
    if (cnt == 0) {
        cout << "0" << endl;
        return 0;
    }
    if (cnt < 0) rev();
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            a++;
        else
            b++;
        if (b > a) {
            cout << b << endl;
            return 0;
        }
    }
    return 0;
}