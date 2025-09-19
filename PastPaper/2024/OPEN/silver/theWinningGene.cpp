#include <bits/stdc++.h>

#include <vector>
using namespace std;
struct Gene {
    string s;
    int n;
    vector<vector<int>> mut;
    Gene(string s, int n) : s(s), n(n), mut(n + 1, vector<int>(n + 1, -1)) {}
    int getMut(int i, int j) {
        if (i == n || j == n) {
            return mut[i][j] = (s[i - 1] == s[j - 1]);
        }
        if (mut[i][j] != -1) return mut[i][j];
        if (s[i - 1] != s[j - 1]) return mut[i][j] = 0;
        return mut[i][j] = getMut(i + 1, j + 1) + 1;
    }

    int cmp(int l, int i, int j) {
        if (i == 0) return -1;
        if (j == 0) return 1;
        if (j + l > n + 1) return 1;
        if (i + l > n + 1) return -1;
        int m = getMut(i, j);
        if (m >= l) return 0;
        if (s[i + m - 1] > s[j + m - 1]) return 1;
        return -1;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("theWinningGene.in", "r", stdin);
    freopen("theWinningGene.out", "w", stdout);
#endif

    int n;
    string s;
    cin >> n >> s;
    Gene gene{s, n};

    vector<vector<int>> res_g(n + 1, vector<int>(n + 1));
    vector<vector<int>> diff_g(n + 1, vector<int>(n + 1));

    vector<int> stk;
    stk.reserve(n + 1);
    vector<int> left(n + 1);
    vector<int> right(n + 1);

    for (int L = 1; L <= n; L++) {
        // prepare variables
        auto& diff = diff_g[L];
        auto& res = res_g[L];

        stk.clear();
        left.clear();
        left.resize(n + 1);
        right.clear();
        right.resize(n + 1);
        // compute  left:

        stk.push_back(0);
        for (int i = 1; i <= n - L + 1; i++) {
            while (gene.cmp(L, i, stk.back()) < 0) stk.pop_back();
            left[i] = stk.back();
            stk.push_back(i);
        }
        // compute right:
        stk.clear();
        stk.push_back(n - L + 2);
        for (int i = n - L + 1; i >= 1; i--) {
            while (gene.cmp(L, i, stk.back()) <= 0) stk.pop_back();
            right[i] = stk.back();
            stk.push_back(i);
        }

        for (int i = 1; i <= n - L + 1; i++) {
            diff[L - 1]++;
            diff[right[i] + L - 2 - left[i]]--;
        }

        for (int i = 1; i <= n; i++) {
            res[i] = res[i - 1] + diff[i - 1];
        }
    }
    vector<int> v(n + 1);
    for (int k = 1; k <= n; k++) {
        for (int L = 1; L <= k; L++) {
            v[res_g[L][k]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << v[i] << endl;
    }
    return 0;
}
