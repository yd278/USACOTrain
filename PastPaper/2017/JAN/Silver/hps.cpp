#include <bits/stdc++.h>
using namespace std;
vector<char> FJ;
int n;

vector<int> H, P, S;

int main() {
#ifndef ONLINE_JUDGE
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
#endif
    cin >> n;
    FJ.resize(n);
    for (int i = 0; i < n; i++) cin >> FJ[i];
    H.resize(n + 1);
    P.resize(n + 1);
    S.resize(n + 1);

    for (int i = 0; i < n; i++) {
        H[i + 1] = H[i];
        P[i + 1] = P[i];
        S[i + 1] = S[i];
        if (FJ[i] == 'H')
            H[i + 1]++;
        else if (FJ[i] == 'P')
            P[i + 1]++;
        else if (FJ[i] == 'S')
            S[i + 1]++;
    }
    int Ht = H[n];
    int Pt = P[n];
    int St = S[n];

    int ans = 0;
    for (int t = 0; t < n; t++) {  // [0,t) [t,n)
        int first = max(max(H[t], P[t]), S[t]);
        int second = max(max(Ht - H[t], Pt - P[t]), St - S[t]);
        if (first + second > ans) ans = first + second;
    }
    cout << ans << endl;
}