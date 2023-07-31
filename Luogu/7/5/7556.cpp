#include <bits/stdc++.h>
using namespace std;

struct Triple {
    int a, b, c;
    bool operator<(const Triple& other) const {
        if (a < other.a) return true;
        if (a == other.a && b < other.b) return true;
        if (a == other.a && b == other.b && c < other.c) return true;
        return false;
    }
};

set<Triple> Triples;

vector<int> full(8);

inline bool sub_veri(int& tmp, int a1, int a2) {
    if (full[a1] && full[a2]) {
        if (!tmp)
            tmp = full[a1] - full[a2];
        else if (full[a1] - full[a2] != tmp)
            return false;
    }
    return true;
}
bool calc_element(int& res, int o, int a1, int a2, int b1, int b2, int c1, int c2) {
    int tmp = 0;
    if (full[o]) tmp = full[o];

    if (!sub_veri(tmp, a1, a2)) return false;
    if (!sub_veri(tmp, b1, b2)) return false;
    if (!sub_veri(tmp, c1, c2)) return false;

    if (full[c1] && full[a2] && full[b2]) {
        if (full[c1] - full[a2] - full[b2] != tmp) return false;
    }
    res = tmp;

    return true;
}
void verification() {
    int fiA, fiB, fiC;
    if (!calc_element(fiA, 1, 3, 2, 5, 4, 7, 6)) return;
    if (!calc_element(fiB, 2, 3, 1, 6, 4, 7, 5)) return;
    if (!calc_element(fiC, 4, 5, 1, 6, 2, 7, 3)) return;
    if (fiA > fiB) return;
    if (fiA > fiC) return;
    if (fiB > fiC) return;
    if(full[3]){
        if(fiA+fiB!=full[3])return;
    }
    if(full[5]){
        if(fiA+fiC!=full[5])return;
    }
    if(full[6]){
        if(fiB+fiC!=full[6])return;
    }
    if(full[7]){
        if(fiA+fiB+fiC!=full[7]) return;
    }
    Triple t = Triple{fiA, fiB, fiC};
    Triples.insert(t);
}

void dfs(int iA, int iT, vector<int> told) {
    if (iA == 8) {
        if (iT == told.size()) {
            verification();
            swap(full[3], full[4]);
            verification();
            swap(full[3], full[4]);
        }
        return;
    }
    dfs(iA + 1, iT, told);
    if (iT < told.size()) {
        full[iA] = told[iT];
        dfs(iA + 1, iT + 1, told);
        full[iA] = 0;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("7556.in", "r", stdin);
    freopen("7556.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Triples.clear();
        int n, a;
        cin >> n;
        vector<int> told;
        for (int i = 0; i < n; i++) {
            cin >> a;
            told.push_back(a);
        }
        sort(told.begin(), told.end());
        dfs(1, 0, told);
        cout << Triples.size() << endl;
    }
}