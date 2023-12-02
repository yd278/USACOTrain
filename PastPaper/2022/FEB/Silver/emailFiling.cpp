#include <bits/stdc++.h>
using namespace std;
void process() {
    int n, m, k;
    cin >> m >> n >> k;
    stack<int> overflowMailTargets;
    vector<int> targetFolder(n);
    vector<int> folderCount(m);
    for (auto &target : targetFolder) {
        cin >> target;
        target--;
        folderCount[target]++;
    }
    list<int> screen;
    for (int i = 0; i < k; i++) {
        screen.push_back(targetFolder[i]);
    }
    int nextMailIndex = k;

    for (int firstFolder = 0; firstFolder < m - k + 1; firstFolder++) {
        auto it = screen.begin();
        while (it != screen.end()) {
            auto tmp = it;
            it++;
            if (*tmp >= firstFolder && *tmp < firstFolder + k) {
                folderCount[*tmp]--;
                screen.erase(tmp);
            }
        }
        while (folderCount[firstFolder] && nextMailIndex < n) {
            if (screen.size() == k) {
                overflowMailTargets.push(screen.front());
                screen.pop_front();
            }
            auto nextTarget = targetFolder[nextMailIndex];
            if (nextTarget >= firstFolder && nextTarget < firstFolder + k) {
                folderCount[nextTarget]--;
            } else {
                screen.push_back(nextTarget);
            }
            nextMailIndex++;
        }
        if (nextMailIndex == n) {
            while (screen.size() < k && overflowMailTargets.size()) {
                auto prevTarget = overflowMailTargets.top();
                if (prevTarget >= firstFolder && prevTarget < firstFolder + k) {
                    folderCount[prevTarget]--;
                } else {
                    screen.push_front(prevTarget);
                }
                overflowMailTargets.pop();
            }
        }
    }
    if (screen.size())
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}
