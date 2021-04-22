/*
ID: dyh2191
LANG: C++14
TASK: combo
*/

#include <iostream>
#include <set>

using namespace std;

int n;
set<int> s;
inline int normalize(int x) {
    while (x > n) x -= n;
    while (x < 1) x += n;
    return x;
}
inline int combine(int a, int b, int c) {
    return (a - 1) * n * n + (b - 1) * n + c - 1;
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("combo.in","r",stdin);
		freopen("combo.out","w",stdout);
	#endif
    int a, b, c;
    int d, e, f;

    cin >> n;
    for (int i = 0; i < 2; i++) {
        cin >> a >> b >> c;

        for (int ia = a - 2; ia <= a + 2; ia++) {
            int na = normalize(ia);
            for (int ib = b - 2; ib <= b + 2; ib++) {
                int nb = normalize(ib);
                for (int ic = c - 2; ic <= c + 2; ic++) {
                    int nc = normalize(ic);
                    s.insert(combine(na, nb, nc));
                }
            }
        }
    }
	cout<<s.size()<<endl;
}