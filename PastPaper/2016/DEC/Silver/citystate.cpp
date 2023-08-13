#include <bits/stdc++.h>
using namespace std;

inline int encode(string s) { return (s[0] - 'A') * 26 + (s[1] - 'A'); }

#define NoS 676
long long cnt[NoS][NoS];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("citystate.in","r",stdin);
        freopen("citystate.out","w",stdout);
    #endif
    int n;
    string city;
    string state;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> city >> state;
        city = city.substr(0, 2);
        cnt[encode(state)][encode(city)]++;
    }
    long long ans = 0;
    for (int i = 0; i < NoS; i++) {
        for (int j = i+1; j < NoS; j++) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << endl;
}
