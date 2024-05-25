#include <bits/stdc++.h>
using namespace std;
void process() {
    int n;
    cin >> n;
    vector<int> hints(n - 1);
    vector<int> count(n + 1);
    for (auto &h : hints) {
        cin >> h;
        count[h]++;
    }

    if (hints[n - 2] != 1) {
        cout << "-1\n";
        return;
    }
    vector<int> endPoint;
    for (int i = 2; i <= n; i++) {
        if (count[i] >= 2) {
            cout << "-1\n";
            return;
        }
        if (count[i] == 0) {
            endPoint.push_back(i);
            if (endPoint.size() > 2) {
                cout << "-1\n";
                return;
            }
        }
    }
    if (count[1] == 1) {
        for (int i = n - 2; i >= 0; i--) {
            cout << hints[i] << ' ';
        }
        cout << endPoint[0] << '\n';
        return;
    }
    if (count[1] != 2) {
        cout << "-1\n";
        return;
    }
    vector<int> ans(n);
    ans[0] = endPoint[0];
    ans[n - 1] = endPoint[1];
    int l = 0;
    int r = n - 1;
    for (int i = 0; i < n - 2; i++) {
        if (ans[l] > ans[r])
            ans[++l] = hints[i];
        else
            ans[--r] = hints[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans.back() << endl;
}
int main() {

    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}