#include <bits/stdc++.h>
using namespace std;

int main() {
    // #ifndef ONLINE_JUDGE
    // 	freopen("CowntactTracing.in","r",stdin);
    // 	freopen("CowntactTracing.out","w",stdout);
    // #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = 0;
    int leftEnd = 0;
    if (s[0] == '1') {
        while (p < n && s[p] == '1') {
            leftEnd++;
            p++;
        }
    }
    if (leftEnd == n) {
        cout << 1 << "\n";
        return 0;
    }

    vector<int> segs;
    for (; p < n; p++) {
        if (s[p] == '1') {
            if (s[p - 1] == '0')
                segs.push_back(1);
            else
                segs.back()++;
        }
    }
    int rightEnd = 0;
    if (s[n - 1] == '1') {
        rightEnd = segs.back();
        segs.pop_back();
    }

    int cover = INT_MAX;
    if (leftEnd) cover = 2 * leftEnd - 1;
    if (rightEnd) cover = min(cover, 2 * rightEnd - 1);

    for (auto t : segs) {
        cover = min(cover, t & 1 ? t : t - 1);
    }

    int ans = 0;
    if (leftEnd) ans += (leftEnd - 1) / cover + 1;
    if (rightEnd) ans += (rightEnd - 1) / cover + 1;
    for (auto s : segs) {
        ans += (s - 1) / cover + 1;
    }
    cout << ans << "\n";

    return 0;
}
