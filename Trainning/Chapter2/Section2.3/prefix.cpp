/*
ID: dyh2191
LANG: C++14
TASK: prefix
*/
#include <iostream>
#include <set>

using namespace std;
int dp[200000];
set<string> primitives[11];
string S;
int main() {
#ifndef ONLINE_JUDGE
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
#endif
    string p;
    cin >> p;
    int maxL = 0;
    while (p != ".") {
        int l = p.length();
        if (maxL < l) maxL = l;
        primitives[l].insert(p);
        cin >> p;
    }
    S = "";
    while (cin >> p) {
        S += p;
    }
    dp[0] = 1;
    int maxAns = 0;
    for (int i = 1; i <= S.length(); i++) {
        for (int j = maxL; j >= 0; j--) {
            if (i - j >= 0) {
                if (dp[i - j]) {
                    string s = S.substr(i - j, j);
                    if (primitives[j].find(s) != primitives[j].end()) {
                        dp[i] = 1;
                        maxAns = i;
                    }
                }
            }
        }
    }
    cout << maxAns << endl;
}