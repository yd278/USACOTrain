/*
ID: dyh2191
LANG: C++14
TASK: ariprog
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct prog {
    int a, p;
};
vector<prog> ans;
vector<int> list;
int cmp(prog a, prog b) {
    if (a.p < b.p) return 1;
    if (a.p == b.p && a.a < b.a) return 1;
    return 0;
}
int s[125001];

int main() {
#ifndef ONLINE_JUDGE
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int p = 0; p <= m; p++) {
        for (int q = p; q <= m; q++) {
            int tmp = p * p + q * q;
            if (s[tmp] == 0) list.push_back(tmp);
            s[tmp] = 1;
        }
    }
    for (int a : list) {
        for (int b : list) {
            if (b <= a) continue;
            int p = b - a;
            int valid = 1;
            for (int k = 2; k < n; k++) {
                if (a + k * p > 2 * m * m){
					valid = 0;
					break;
				} 
                if (!s[a + k * p]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                ans.push_back(prog{a, p});
            }
        }
    }
    if (ans.size() == 0) {
        cout << "NONE" << endl;
    } else {
        sort(ans.begin(), ans.end(), cmp);
        for (auto a : ans) {
            cout << a.a << " " << a.p << endl;
        }
    }
}