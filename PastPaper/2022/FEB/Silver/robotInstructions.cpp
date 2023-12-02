#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point &other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
	Point operator+(const Point &other) const{
		return {x+other.x, y+other.y};
	}
	Point operator-(const Point &other) const{
		return {x-other.x, y-other.y};
	}
};

struct Sol{
	Point point;
	long long steps;

    bool operator<(const Sol &other) const {
        return tie(point, steps) < tie(other.point, other.steps);
    }
    bool operator==(const Sol &other) const {
        return point == other.point && steps == other.steps;
    }
};

struct SolCount{
	Sol sol;
	long long cnt;
	 bool operator<(const SolCount &other) const {
        return tie(sol, cnt) < tie(other.sol, other.cnt);
    }
    bool operator==(const SolCount &other) const {
        return sol == other.sol && cnt == other.cnt;
    }
};


int main() {

    int n;
    cin >> n;
    Point target;
    cin >> target.x >> target.y;
    vector<Point> instructions(n);

    for (auto &p : instructions) {
        cin >> p.x >> p.y;
    }


    vector<Sol> head;
    head.push_back({{0, 0}, 0});
    for (int i = 0; i < n / 2; i++) {
        int t = head.size();
        head.resize(t * 2);
        for (int j = 0; j < t; j++) {
            auto &a = head[j];
            auto &b = head[j + t];
            b.point = a.point + instructions[i];
            b.steps = a.steps + 1;
        }
    }
    sort(head.begin(), head.end());
    vector<SolCount> headCount;
    Sol prevSol = {{INTMAX_MAX, INTMAX_MAX}, -1};
    for (auto s : head) {
        if (! (s == prevSol)) {
            prevSol = s;
            headCount.push_back({s, 1});
        } else {
            headCount.back().cnt++;
        }
    }

    vector<Sol> tail;
    tail.push_back({target, 0});
    for (int i = n / 2; i < n; i++) {
        int t = tail.size();
        tail.resize(t * 2);
        for (int j = 0; j < t; j++) {
            auto &a = tail[j];
            auto &b = tail[j + t];
            b.point = a.point- instructions[i];
            b.steps = a.steps + 1;
        }
    }
    sort(tail.begin(), tail.end());
    vector<SolCount> tailCount;
    prevSol = {{INTMAX_MAX, INTMAX_MAX}, INT_MAX};
    for (auto s : tail) {
        if (!(s == prevSol)) {
            prevSol = s;
            tailCount.push_back({s, 1});
        } else {
            tailCount.back().cnt++;
        }
    }
    vector<long long> ans(n + 1);
    int headPtr = 0;
    int tailPtr = 0;
    while (headPtr < headCount.size()) {
        auto h = headCount[headPtr];
        while (tailPtr < tailCount.size() &&
               (tailCount[tailPtr].sol.point < h.sol.point))
            tailPtr++;
        if (tailPtr == tailCount.size()) break;
        if (tailCount[tailPtr].sol.point == h.sol.point) {
            for (int ptr = tailPtr;
                 tailCount[ptr].sol.point == tailCount[tailPtr].sol.point;
                 ptr++) {
                ans[headCount[headPtr].sol.steps +
                    tailCount[ptr].sol.steps] +=
                    headCount[headPtr].cnt * tailCount[ptr].cnt;

            }
        }
		headPtr++;
    }
	for(int i = 1; i <= n; i++){
		cout<<ans[i]<<endl;
	}

    return 0;
}
