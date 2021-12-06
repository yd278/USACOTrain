#include <iostream>
#include <stack>
using namespace std;

stack<int> bracket;

int matched[100];
int main() {
#ifndef ONLINE_JUDGE
    freopen("1241.in", "r", stdin);
    freopen("1241.out", "w", stdout);
#endif
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') bracket.push(i);
        if (s[i] == '(') bracket.push(i);
        if (s[i] == ']') {
            if (!bracket.empty()) {
                int t = bracket.top();
                if (s[t] == '[') {
                    matched[t] = 1;
                    matched[i] = 1;
                    bracket.pop();
                }
            }
        }
        if (s[i] == ')') {
            if (!bracket.empty()) {
                int t = bracket.top();
                if(s[t]=='(')
                {matched[i] = 1;
                matched[t] = 1;
                bracket.pop();}
            }
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (matched[i])
            cout << s[i];
        else {
            if (s[i] == '(' || s[i] == ')')
                cout << "()";
            else
                cout << "[]";
        }
    }
    return 0;
}