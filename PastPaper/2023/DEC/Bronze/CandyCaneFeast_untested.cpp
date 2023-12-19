#include <iostream>
#include <vector>

typedef long long ll;

struct Cow {
    ll height;
    int index;
    bool operator<(const Cow &other) const { return height < other.height; }
};

inline void push(std::vector<Cow> &cows, const Cow &x) {
    if (cows.back() < x) cows.push_back(x);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("CandyCaneFeast.in", "r", stdin);
//     freopen("CandyCaneFeast.out", "w", stdout);
// #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<Cow> cows(n);

    for (int i = 0; i < n; i++) {
        std::cin >> cows[i].height;
        cows[i].index = i;
    }

    ll cane;
    std::vector<Cow> feed;
	feed.reserve(n+1);
    feed.push_back({0ll, -1});
    for (int i = 0; i < n; i++) {
        push(feed, cows[i]);
    }

	std::vector<Cow> nxt;
	nxt.reserve(n+1);
    for (int i = 0; i < m; i++) {
        ll prev = 0ll;
        std::cin >> cane;
		nxt.clear();
        nxt.push_back({0ll, -1});
        for (auto &cow : feed) {
            if (cow.height > cane) {
                ll newHeight = cow.height + cane - prev;
                cows[cow.index].height = newHeight;
                push(nxt, {newHeight, cow.index});
                break;
            }
            ll newHeight = cow.height + cow.height - prev;
            prev = cow.height;
            cows[cow.index].height = newHeight;
            push(nxt, {newHeight, cow.index});
        }
        feed = nxt;
    }
    for (auto &cow : cows) {
        std::cout << cow.height << "\n";
    }

    return 0;
}
