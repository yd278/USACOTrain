#include <bits/stdc++.h>
using namespace std;
bitset<200001> target;
int t, c;
inline bool isTarget(int x) { return target[x + c]; }
inline void setTarget(int x) { target.set(x + c); }
map<int, int> hitCount;
inline void hit(int x) {
    if (!isTarget(x)) return;
    if (hitCount.count(x) == 0) {
        hitCount[x] = 1;
    } else {
        hitCount[x] += 1;
    }
}
inline void unhit(int x) {
    if (hitCount.count(x) == 0) return;
    hitCount[x] -= 1;
    if (hitCount[x] == 0) hitCount.erase(x);
}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("TargetPractice.in", "r", stdin);
//     freopen("TargetPractice.out", "w", stdout);
// #endif
    cin >> t >> c;
    for (int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        setTarget(tmp);
    }

    string ins;
    cin >> ins;

    // simulation:
    int pos = 0;
    vector<int> cent(c);
    for (int i = 0; i < c; i++) {
        cent[i] = pos;
        if (ins[i] == 'L') pos--;
        if (ins[i] == 'R') pos++;
        if (ins[i] == 'F') {
            hit(pos);
        }
    }
    int maxAns = hitCount.size();
    auto hitBackup = hitCount;
    int offset = -2;
    if (c >= 2) {

    	// R->L
        for (int i = c - 1; i >= 0; i--) {
            if (ins[i] != 'R') {
                if (ins[i] == 'F') {
                    unhit(cent[i]);
                    hit(cent[i] + offset);
                }
            } else {
                maxAns = max(maxAns, (int)hitCount.size());
            }
        }
        // L->R
        hitCount = hitBackup;
        offset = 2;
        for (int i = c - 1; i >= 0; i--) {
            if (ins[i] != 'L') {
                if (ins[i] == 'F') {
                    unhit(cent[i]);
                    hit(cent[i] + offset);
                }
            } else {
                maxAns = max(maxAns, (int)hitCount.size());
            }
        }
    }
    // R->F or F->L
    hitCount = hitBackup;
    offset = -1;
    for (int i = c - 1; i >= 0; i--) {
        if (ins[i] == 'R') {
            // change here
            hit(cent[i]);
            maxAns = max(maxAns, (int)hitCount.size());
            unhit(cent[i]);
            // change earlier
            // nothing happend;
        } else if (ins[i] == 'F') {
            // change here
            unhit(cent[i]);
            maxAns = max(maxAns, (int)hitCount.size());
            // hit
            // change earlier
            // unhit
            hit(cent[i] + offset);
        }
    }
    hitCount = hitBackup;
    offset = 1;
    for (int i = c - 1; i >= 0; i--) {
        if (ins[i] == 'L') {
            // change here
            hit(cent[i]);
            maxAns = max(maxAns, (int)hitCount.size());
            unhit(cent[i]);
            // change earlier
            // nothing happend;
        } else if (ins[i] == 'F') {
            // change here
            unhit(cent[i]);
            maxAns = max(maxAns, (int)hitCount.size());
            // hit
            // change earlier
            // unhit
            hit(cent[i] + offset);
        }
    }

    cout << maxAns << endl;

    return 0;
}
