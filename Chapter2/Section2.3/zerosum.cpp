/*
ID: dyh2191
LANG: C++14
TASK: zerosum
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n;
stack<int> operands;
stack<char> operators;
vector<string> ans;
string toStr(int num) {
    string res = "";
    while (num) {
        int x = num % 10;
        res = (char)(x + '0') + res;
        if (num / 10) res = " " + res;
        num /= 10;
    }
    return res;
}
int eval() {
    auto operands_tmp = operands;
    auto operators_tmp = operators;
    int res;
    while (!operators_tmp.empty()) {
        char Operator = operators_tmp.top();
        operators_tmp.pop();
        int operands_1 = operands_tmp.top();
        operands_tmp.pop();
        int operands_2 = operands_tmp.top();
        operands_tmp.pop();
        if (Operator == '+') {
            operands_tmp.push(operands_1 + operands_2);
        } else {
            operands_tmp.push(operands_1 - operands_2);
        }
    }
    return operands_tmp.top();
}
void print() {
    string result = "";
    auto operands_tmp = operands;
    auto operators_tmp = operators;
    int tmp = operands_tmp.top();
    result += toStr(tmp);
    operands_tmp.pop();
    while (!operands_tmp.empty()) {
        char op = operators_tmp.top();
        result = result + op;
        operators_tmp.pop();
        int opd = operands_tmp.top();
        result = result + toStr(opd);
        operands_tmp.pop();
    }
    ans.push_back(result);
}
int cat(int x, int y) {
    int t = y;
    while (t) {
        t /= 10;
        x *= 10;
    }
    return x + y;
}
int cut(int x) {
    int shift = 1;
    while (shift < x) {
        shift *= 10;
    }
    return x % shift;
}
void dfs(int x) {
    if (x == 0) {
        if (eval() == 0) {
            print();
        }
        return;
    }
    operators.push('+');
    operands.push(x);
    dfs(x - 1);
    operands.pop();
    operators.pop();
    operators.push('-');
    operands.push(x);
    dfs(x - 1);
    operands.pop();
    operators.pop();
    int tmp = operands.top();
    operands.pop();
    operands.push(cat(x, tmp));
    dfs(x - 1);
    tmp = operands.top();
    operands.pop();
    operands.push(cut(tmp));
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
#endif
    cin >> n;
    operands.push(n);
    dfs(n - 1);
    sort(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << endl;
    }
    return 0;
}