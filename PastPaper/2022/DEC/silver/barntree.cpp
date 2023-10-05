#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> sum;
vector<ll> hay;
vector<ll> cnt;
vector<vector<int>> edges;
struct Move {
    int from, to;
    ll amt;
};
vector<Move> ans;
void calcSum(int x, int pr) {
    for (int to : edges[x]) {
        if (to == pr) continue;
        calcSum(to, x);
        sum[x] += sum[to];
        cnt[x] += cnt[to];
    }
    sum[x] += hay[x];
    cnt[x]++;
}

void process(int x, int pr, ll avg) {
    for (int to : edges[x]) {
        if (to == pr) continue;
        if (sum[to] >= avg * cnt[to]) {
            process(to, x, avg);
            if (sum[to] - avg * cnt[to]) {
                ans.push_back({to, x, sum[to] - avg * cnt[to]});
                sum[to] = avg * cnt[to];
            }
        }
    }
    for (int to : edges[x]) {
        if (to == pr) continue;
        if (sum[to] < avg * cnt[to]) {
            ans.push_back({x, to, avg * cnt[to] - sum[to]});
            sum[to] = avg * cnt[to];
            process(to, x, avg);
        }
    }
}

int main() {

    int n;
    cin >> n;
    sum.resize(n + 1);
    hay.resize(n + 1);
    edges.resize(n + 1);
    cnt.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> hay[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    calcSum(1, 0);
    process(1, 0, sum[1] / n);
    cout << ans.size() << endl;
    for (auto m : ans) {
        cout << m.from << " " << m.to << " " << m.amt << endl;
    }
    return 0;
}