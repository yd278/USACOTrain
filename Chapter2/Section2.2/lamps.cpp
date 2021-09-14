/*
ID: dyh2191
LANG: C++14
TASK: lamps
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int lamps[101];
vector<int> onList;
vector<int> offList;
vector<string> ans;
int n;
void print() {
    string res = "";
    for (int i = 1; i <= n; i++) res += lamps[i] ? "1" : "0";
    res += "\n";
    for (auto x : ans) {
        if (x == res) return;
    }
    ans.push_back(res);
}
void b1() {
    for (int i = 1; i <= n; i++) {
        lamps[i] = !lamps[i];
    }
}
void b2() {
    for (int i = 1; i <= n; i += 2) {
        lamps[i] = !lamps[i];
    }
}

void b3() {
    for (int i = 2; i <= n; i += 2) {
        lamps[i] = !lamps[i];
    }
}
void b4() {
    for (int i = 1; i <= n; i += 3) {
        lamps[i] = !lamps[i];
    }
}
void b(int k) {
    if (k == 1)
        b1();
    else if (k == 2)
        b2();
    else if (k == 3)
        b3();
    else if (k == 4)
        b4();
}
int check() {
    for (int x : onList)
        if (!lamps[x]) return 0;

    for (int x : offList)
        if (lamps[x]) return 0;

    return 1;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
#endif
    int c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) lamps[i] = 1;

    int a;
    cin >> a;
    while (a != -1) {
        onList.push_back(a);
        cin >> a;
    }
    cin >> a;
    while (a != -1) {
        offList.push_back(a);
        cin >> a;
    }

    if (c == 0) {
        if (offList.size() != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        else {
            for (int i = 0; i < n; i++) cout << 1;
            cout << endl;
            return 0;
        }
    }
    if (c == 1) {
        for (int i = 1; i <= 4; i++) {
            b(i);
            if (check()) print();

            b(i);
        }
        if (ans.size() == 0)
            cout << "IMPOSSIBLE" << endl;
        else {
            sort(ans.begin(), ans.end());
            for (auto a : ans) cout << a;
        }
        return 0;
    }
    if (c == 2) {
        if (check()) print();
        for (int i = 1; i <= 4; i++) {
            b(i);
            if (check()) print();

            b(i);
        }
        for (int i = 1; i <= 3; i++) {
            b(i);
            b(4);
            if (check()) print();
            b(4);
            b(i);
        }
        if (ans.size() == 0)
            cout << "IMPOSSIBLE" << endl;
        else {
            sort(ans.begin(), ans.end());
            for (auto a : ans) cout << a;
        }
        return 0;
    }

    if (check()) print();
    for (int i = 1; i <= 4; i++) {
        b(i);
        if (check()) print();

        b(i);
    }
    for (int i = 1; i <= 4; i++) {
        b(i);
        for (int j = i; j <= 4; j++) {
            b(j);
            if (check()) print();

            b(j);
        }
        b(i);
    }
    if (ans.size() == 0)
        cout << "IMPOSSIBLE" << endl;
    else {
        sort(ans.begin(), ans.end());
        for (auto a : ans) cout << a;
    }
    return 0;
}
