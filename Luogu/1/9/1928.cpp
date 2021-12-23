#include <iostream>
using namespace std;
inline int isNum(char x) { return x <= '9' && x >= '0'; }
string decode(string code) {
    int repeat = 0;
    int index = 0;
    int cnt = 0;
    string res = "";
    string tmp = "";
    while (isNum(code[index])) {
        repeat = repeat * 10 + code[index] - '0';
        index++;
    }
    while (index < code.length()) {
        if (code[index] == ']') {
            cnt--;
            if (cnt == 0) {
                res += decode(tmp);
                tmp = "";
            }
        }
        if (cnt > 0) {
            tmp += code[index];
        } else {
            if (code[index] != '[' && code[index] != ']') res += code[index];
        }
        if (code[index] == '[') cnt++;
        index++;
    }
    if (repeat == 0) repeat = 1;
    string fin = "";
    for (int i = 0; i < repeat; i++) {
        fin += res;
    }
    return fin;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1928.in", "r", stdin);
    freopen("1928.out", "w", stdout);
#endif
    string s;
    cin >> s;
    cout << decode(s) << endl;
}