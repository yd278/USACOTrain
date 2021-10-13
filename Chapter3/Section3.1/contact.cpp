/*
ID: dyh2191
LANG: C++14
TASK: contact
*/
#include <algorithm>
#include <iostream>
using namespace std;
string sig;
struct patten {
    int count;
    int encode;
    bool operator<(const patten &other) const {
        if (count > other.count) return true;
        if (count == other.count) return encode < other.encode;
        return false;
    }
} pattens[16384];
string decode(int x) {
    string res = "";
    while (x > 1) {
        string tmp = (x % 2) ? "1" : "0";
        res = tmp + res;
        x /= 2;
    }
    return res;
}
void process(int len) {
    int encode = 0;
    int mask = 1 << len;
    for (int i = 0; i < len; i++) {
        encode *= 2;
        encode += (sig[i] == '1');
    }
    encode += mask;
    pattens[encode].count++;
    for (int i = len; i < sig.length(); i++) {
        encode *= 2;
        encode += (sig[i] == '1');
        encode %= mask;
        encode += mask;
        pattens[encode].count++;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
#endif
    int a, b, n;
    cin >> a >> b >> n;
    string tmp;
    while (cin >> tmp) {
        sig += tmp;
    }
    for (int i = a; i <= b; i++) {
        if (i <= sig.length()) process(i);
    }
    for (int i = 0; i < 1 << (b + 1); i++) {
        pattens[i].encode = i;
    }
    sort(pattens, pattens + 16384);
    cout << pattens[0].count << endl;
    cout << decode(pattens[0].encode);
    int prev = pattens[0].count;
    int cnt = 1;
    int linecnt = 1;
    for (int i = 1;; i++) {
        if (pattens[i].count != prev) {
            cnt++;
            if (cnt > n) break;
            if(pattens[i].count==0)break;
            cout << endl
                 << pattens[i].count << endl
                 << decode(pattens[i].encode);
            prev = pattens[i].count;
            linecnt = 1;

        } else {
            if(linecnt == 6){
                cout<<endl;
                linecnt=0;
            }

            else cout<<" ";
            cout <<decode(pattens[i].encode);
            linecnt ++;
        }
    }
    cout << endl;
}