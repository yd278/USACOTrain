#include <bits/stdc++.h>

using namespace std;
vector<vector<vector<long long>>> dp(2);
int N;
long long T;
vector<int> num(2);
vector<vector<long long>> times(2);
long long ans = INTMAX_MAX;
inline void minimize(long long &a, long long b) {
    if (b < a) a = b;
}
void push_forward(int cur, int forward) {
    int backward = 1 - forward;
#define f dp[forward]
#define b dp[backward]
#define nF num[forward]
#define nB num[backward]
#define tF times[forward]
#define tB times[backward]
    if (cur != nF)
        for (int j = 0; j <= nB; j++) {
            if (f[cur][j] != INTMAX_MAX) minimize(f[cur + 1][j], f[cur][j]);
        }

    long long t = tF[cur] + T;
    int x = nB + 1;
    while (tB[x - 1] >= t) x--;

    long long minCost = INTMAX_MAX;
    long long extra = 0;
    minimize(minCost, f[cur][x - 1]);
    for (int j = x - 1; j > 0; j--) {
        extra += t - tB[j];
		if(f[cur][j-1]!=INTMAX_MAX)
        	minimize(minCost, f[cur][j - 1] + extra);
    }
    vector<int> next(2);
#define pF next[forward]
#define pB next[backward]
    pF = cur + 1;
    pB = x;
    for (int k = 1; k <= N; k++, t += T) {
        forward = 1 - forward;
        backward = 1 - backward;
        while (pF <= nF && tF[pF] < t) {
            minCost += t - tF[pF];
            pF++;
        };
        if (pF == nF + 1) {
            if (pB == nB + 1) {
                minimize(ans, minCost);
            }
        } else {
            minimize(f[pF][pB - 1], minCost);
        }
    }
}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("trainScheduling.in", "r", stdin);
//     freopen("trainScheduling.out", "w", stdout);
// #endif
#define A 0
#define B 1
    cin >> N >> T;
    char c;
    long long t;
    for (int i = 0; i < N; i++) {
        cin >> c >> t;
        if (c == 'A')
            times[A].push_back(t);
        else
            times[B].push_back(t);
    }

    for (int side : {A, B}) {
        num[side] = times[side].size();
        times[side].push_back(0);
        sort(times[side].begin(), times[side].end());
    }
    if (num[A] == 0 || num[B] == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (auto side : {A, B}) {
        dp[side].resize(num[side] + 1);
        for (auto &row : dp[side]) {
            row.resize(num[1 - side] + 1);
            for (auto &element : row) {
                element = INTMAX_MAX;
            }
        }
        dp[side][1][0] = 0;
    }

    vector<int> p = {1, 1};
    while (p[A] <= num[A] && p[B] <= num[B]) {
        if (times[A][p[A]] < times[B][p[B]]) {
            push_forward(p[A], A);
            p[A]++;
        } else {
            push_forward(p[B], B);
            p[B]++;
        }
    }

    for (auto side : {A, B}) {
        while (p[side] <= num[side]) {
            push_forward(p[side], side);
            p[side]++;
        }
    }
	cout<<ans<<endl;
    return 0;
}
