#include <bits/stdc++.h>
using namespace std;
struct Cow {
    int prod;
    int index;
    bool operator<(const Cow &other) const { return prod < other.prod; }
};
int main() {

    vector<Cow> cows;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cows.push_back({p, i});
    }
    sort(cows.begin(), cows.end());
    vector<int> rank(n);
    for (int i = 0; i < n; i++) {
        rank[cows[i].index] = i;
    }

    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + cows[i].prod;
    }
    long long base = 0;
    for (int i = 0; i < n; i++) {
        base += (i + 1LL) * cows[i].prod;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        if (b == cows[rank[a]].prod) {
            cout << base << endl;
            continue;
        }

        if (b > cows[rank[a]].prod) {
            int p =
                upper_bound(cows.begin(), cows.end(), Cow{b, 0}) - cows.begin();
            int q = rank[a];
            long long ans = base - (sum[p] - sum[q + 1]);
            ans -= (rank[a] + 1LL) * cows[rank[a]].prod;
            ans += (long long)b * p;
            cout << ans << endl;
            continue;
        }

        if (b < cows[rank[a]].prod) {
            int p =
                lower_bound(cows.begin(), cows.end(), Cow{b, 0}) - cows.begin();
            int q = rank[a];
            long long ans = base + (sum[q] - sum[p]);
            ans -= (rank[a] + 1LL) * cows[rank[a]].prod;
            ans += b * (p + 1LL);
            cout << ans << endl;
        }
    }
    return 0;
}