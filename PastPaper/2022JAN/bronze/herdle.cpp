#include <iostream>
#include <string>
using namespace std;

int guess[26];
int target[26];

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("herdle.in", "r", stdin);
//     freopen("herdle.out", "w", stdout);
// #endif
    string guessS = "";
    string targetS = "";
    string tmp;
    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        guessS += tmp;
    }
    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        targetS += tmp;
    }

    int green = 0;
    for (int i = 0; i < 9; i++) {
        if (guessS[i] == targetS[i]) {
            green++;
        } else {
            target[targetS[i] - 'A']++;
            guess[guessS[i] - 'A']++;
        }
    }
    cout << green << endl;
    int yellow = 0;
    for (int i = 0; i < 26; i++) {
        yellow += min(target[i], guess[i]);
    }
    cout << yellow << endl;
    return 0;
}