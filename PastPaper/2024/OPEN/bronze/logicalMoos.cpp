#include <bits/stdc++.h>
using namespace std;
struct query {
    int l, r;
    bool t;
    bool tB, fB, tT, fT;
    bool ans;
};
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> s(n);
    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == "false") {
            s[i] = 0;
        } else if (input == "true") {
            s[i] = 1;
        } else if (input == "and") {
            s[i] = 2;
        } else if (input == "or") {
            s[i] = 3;
        }
    }
    vector<vector<int>> lQuery(n);
    vector<vector<int>> rQuery(n);
    vector<query> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cin >> input;
        queries[i].l = l;
        queries[i].r = r;
        queries[i].t = input == "true";

        lQuery[l].push_back(i);
        rQuery[r].push_back(i);
    }

    bool sB, sT;
    sB = false;
    sT = s[0];
    for (auto index : lQuery[0]) {
        auto &q = queries[index];
        q.tB = false;
        q.fB = false;
        q.tT = true;
        q.fT = false;
    }
    for (int i = 1; i < n; i += 2) {
        for (int index : lQuery[i + 1]) {
            auto &q = queries[index];
            if (s[i] == 2) {
                q.tB = sB;
                q.fB = sB;
                q.tT = sT && true;
                q.fT = false;
            } else {
                q.tB = sB || sT;
                q.fB = sB || sT;
                q.tT = true;
                q.fT = false;
            }
        }
        if (s[i] == 2) {
            sT = sT && s[i + 1];
        } else {
            sB = sT || sB;
            sT = s[i + 1];
        }
    }

    sB = false;
    sT = s[n - 1];
    for (int index : rQuery[n - 1]) {
        auto &q = queries[index];
        bool tRes, fRes;
        tRes = q.tB || q.tT;
        fRes = q.fB || q.fT;
        if (tRes == q.t || fRes == q.t) q.ans = true;
    }

    for (int i = n - 2; i >= 0; i -= 2) {
        for (int index : rQuery[i - 1]) {
            auto &q = queries[index];
            bool tRes, fRes;
            if (s[i] == 2) {
                tRes = q.tB || (q.tT && sT) || sB;
                fRes = q.fB || (q.fT && sT) || sB;
                if (tRes == q.t || fRes == q.t) q.ans = true;
            } else {
                tRes = q.tB || q.tT || sT || sB;
                fRes = q.fB || q.fT || sT || sB;
                if (tRes == q.t || fRes == q.t) q.ans = true;
            }
        }
        if (s[i] == 2) {
            sT = sT && s[i - 1];
        } else {
            sB = sB || sT;
            sT = s[i - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        cout << (queries[i].ans ? "Y" : "N");
    }
    cout << endl;
    return 0;
}