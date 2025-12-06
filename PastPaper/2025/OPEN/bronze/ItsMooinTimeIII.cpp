#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("ItsMooinTimeIII.in", "r", stdin);
    freopen("ItsMooinTimeIII.out", "w", stdout);
#endif
    vector<vector<long long>> pos(26, vector<long long>());
    int n, q;
    cin >> n >> q;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        pos[c - 'a'].push_back(i + 1);
    }
    long long l, r;
    for (int i = 0; i < q; i++) {
        long long ans = -1;
        cin >> l >> r;
        for (int M = 0; M < 26; M++) {
            auto& pM = pos[M];
            auto mpos_i = lower_bound(pM.begin(), pM.end(), l);
            if (mpos_i == pM.end()) continue;
            auto mpos = *mpos_i;
            if (mpos > r || mpos < l) continue;

            for (int O = 0; O < 26; O++) {
                if (M == O) continue;
                auto& pO = pos[O];

                auto opos_i = upper_bound(pO.begin(), pO.end(), r);
                if (opos_i == pO.begin()) continue;
                auto opos = *(opos_i - 1);
                if (opos > r || opos < l) continue;

                long long mid = (mpos + opos) / 2;

                auto mid_i = lower_bound(pO.begin(), pO.end(), mid);
                if (mid_i != pO.end()) {
                    long long mopos = *mid_i;
                    if (mopos > r || mopos < l) continue;
                    if (mopos != opos) {
                        auto res = (mopos - mpos) * (opos - mopos);
                        if (res > ans) ans = res;
                    }
                }

                mid_i = upper_bound(pO.begin(), pO.end(), mid);
                if (mid_i != pO.begin()) {
                    long long mopos = *(mid_i - 1);
                    if (mopos > r || mopos < l) continue;
                    if (mopos != opos) {
                        auto res = (mopos - mpos) * (opos - mopos);
                        if (res > ans) ans = res;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
