#include <bits/stdc++.h>
using namespace std;
struct Cow {
    int a, t;
    int seniority;
    bool operator<(const Cow &other) const {
        return seniority < other.seniority;
    }
};
bool cmp(const Cow &a, const Cow &b) { return a.a < b.a; }
struct cmpS{
    bool operator() (const Cow &a, const Cow b){
        return a.seniority < b.seniority;
    }
};
class Solution {
   public:
    int n;

    int first;
    int curTime;
    int ans = 0;
    priority_queue<Cow, vector<Cow>,cmpS> waiting ;
    vector<Cow> cows;

    void push_time(int time) {
        curTime = time;
        while (first<cows.size() && cows[first].a <= curTime) {
            waiting.push(cows[first]);
            first++;
        }
    }
    void init() {
        cin >> n;
        cows.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> cows[i].a >> cows[i].t;
            cows[i].seniority = n - i;
        }
        sort(cows.begin(), cows.end(), cmp);
        first = 1;
        push_time(cows[0].a + cows[0].t);
    }

    void nextCow() {
        if (!waiting.empty()) {
            auto cow = waiting.top();
            waiting.pop();
            if (curTime - cow.a > ans) ans = curTime - cow.a;
            push_time(curTime + cow.t);
        } else {
            auto cow = cows[first];
            first++;
            push_time(cow.a + cow.t);
        }
    }
    void process(){
        for(int i = 0; i < n-1; i++){
            nextCow();
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
#endif
    Solution solution;
    solution.init();
    solution.process();
    cout<<solution.ans<<endl;
}