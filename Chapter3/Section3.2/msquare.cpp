/*
ID: dyh2191
LANG: C++14
TASK: msquare
*/
#include <iostream>
#include <queue>
using namespace std;

const int fac[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

int contor(string s) {
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        int smaller = 0;
        for (int j = i + 1; j < 8; j++) {
            if (s[i] > s[j]) smaller++;
        }
        ans += smaller * fac[8 - i - 1];
    }
    return ans;
}
int visited[40320];
string reachBy[40320];

string A(string ori) {
    string target(8, ' ');
    for (int i = 0; i < 8; i++) {
        target[i] = ori[8 - i - 1];
    }
    return target;
}

string B(string ori) {
    string target(ori);
    char t = target[3];
    for (int i = 3; i >= 1; i--) target[i] = target[i - 1];
    target[0] = t;
    t = target[4];
    for (int i = 4; i <= 6; i++) target[i] = target[i + 1];
    target[7] = t;
    return target;
}

string C(string ori) {
    string target(ori);
    char t = target[6];
    target[6] = target[5];
    target[5] = target[2];
    target[2] = target[1];
    target[1] = t;
    return target;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
#endif
    string target;
    int a;
    for (int i = 0; i < 8; i++) {
        cin >> a;
        target += char(a) + '0';
    }

    queue<string> q;

    q.push("12345678");
    visited[0] = 1;
    reachBy[0] = "";
    while (!q.empty()) {
        string qh = q.front();
      
        q.pop();
        int index = contor(qh);  
        if(qh==target){
            cout<<reachBy[index].size()<<endl;
            cout<<reachBy[index]<<endl;
            return 0;
        }
        string path = reachBy[index];

        string tmp = A(qh);
        int tmp_index = contor(tmp);
        if (!visited[tmp_index]) {
            q.push(tmp);
            visited[tmp_index] = 1;
            reachBy[tmp_index] = reachBy[index] + "A";
        }

        tmp = B(qh);
        tmp_index = contor(tmp);
        if (!visited[tmp_index]) {
            q.push(tmp);
            visited[tmp_index] = 1;
            reachBy[tmp_index] = reachBy[index] + "B";
        }
        tmp = C(qh);
        tmp_index = contor(tmp);
        if (!visited[tmp_index]) {
            q.push(tmp);
            visited[tmp_index] = 1;
            reachBy[tmp_index] = reachBy[index] + "C";
        }
    }
    return 0;
}