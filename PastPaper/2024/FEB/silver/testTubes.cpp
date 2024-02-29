#include <bits/stdc++.h>
using namespace std;
void process() {
    int n, p;
    cin >> n >> p;
    char aBottom;
    cin >> aBottom;
    char prev = aBottom;
    char tmp;
    int A = 1;
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        if (tmp != prev) {
            A++;
            prev = tmp;
        }
    }
    char bBottom;
    cin >> bBottom;
    prev = bBottom;
    int B = 1;
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        if (tmp != prev) {
            B++;
            prev = tmp;
        }
    }

    if (aBottom == bBottom) B++;
    if (A + B == 3) {
        cout << 1 << "\n";
        if (p > 1) {
            if (A > B)
                cout << "1 2\n";
            else
                cout << "2 1\n";
        }
		return;
    }
    if(A+B==2){
        cout<<"0\n";
        return;
    }
    cout << A + B - 1 << endl;
    bool flip = false;
    if (p > 1) {
        if(A==1) flip = true;
        while (A > 1 || B > 1) {
            if ((A ^ B) & 1) {
                if (A > B) {
                    cout << "1 2\n";
                    A--;
                } else {
                    cout << "2 1\n";
                    B--;
                }
            } else {
                if ((A & 1)^flip) {
                    cout << "1 3\n";
                    A--;
                } else {
                    cout << "2 3\n";
                    B--;
                }
            }
        }
        if(flip) cout<<"3 2\n";
        else cout << "3 1\n";
    }
}
int main() {

    int T;
    cin >> T;
    while (T--) {
        process();
    }
    return 0;
}
