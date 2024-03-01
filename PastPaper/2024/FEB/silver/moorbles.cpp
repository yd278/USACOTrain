#include <bits/stdc++.h>
using namespace std;
void process() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> bessie(k);

    vector<vector<int>> loss(2);
    loss[0].resize(m);
    loss[1].resize(m);

    for (int i = 0; i < m; i++) {
        for (auto &b : bessie) {
            cin >> b;
        }
        int maxEven = INT_MIN;
        int maxOdd = INT_MIN;
        for (auto b : bessie) {
            if (b & 1) {
                if (b > maxOdd) maxOdd = b;
                if (-b > maxEven) maxEven = -b;
            } else {
                if (b > maxEven) maxEven = b;
                if (-b > maxOdd) maxOdd = -b;
            }
        }

        loss[0][i] = maxOdd;
        loss[1][i] = maxEven;
    }

    vector<int> elsie(m);
    vector<int> sum(m + 1);

    for (int i = m - 1; i >= 0; i--) {
        sum[i] = sum[i + 1] + min(loss[1][i], loss[0][i]);
    }
    vector<int> minSum(m+1);
    minSum[m] = sum[m];
    for(int i = m - 1; i>= 0; i--){
        minSum[i] = min(sum[i],minSum[i+1]);
    }
    if (sum[0] >= n) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < m; i++) {
        if (n > loss[0][i] + max(0, sum[i + 1] - minSum[i+1])) {
            n -= loss[0][i];
            // elsie[i] = 0;
        } else {
            if (n > loss[1][i] + max(0, sum[i + 1] - minSum[i+1])) {
                n -= loss[1][i];
                elsie[i] = 1;
            } else {
                cout << "-1\n";
                return;
            }
        }
    }

    for (int i = 0; i < m - 1; i++) {
        cout << (elsie[i] ? "Odd " : "Even ");
    }
    cout << (elsie[m - 1] ? "Odd\n" : "Even\n");
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        process();
    }
    return 0;
}
