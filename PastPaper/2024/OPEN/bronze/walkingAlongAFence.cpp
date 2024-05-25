#include <bits/stdc++.h>
using namespace std;
struct Fence {
    int sX, sY;
    int eX, eY;
    int len;
};

bool cmpV(Fence &x, Fence &y) { return (x.sY < y.sY); }
bool cmpH(Fence &x, Fence &y) { return (x.sX < y.sX); }
inline bool inBetween(int x, int a, int b) {
    if (a > b) swap(a, b);
    return (x >= a && x <= b);
}

int compute(int x, int y, vector<Fence> &ver, vector<Fence> &hor) {
    if (ver.size() != 0) {
        int l = 0;
        int r = ver.size() - 1;
        int mid = (l + r) / 2;
        while (l <= r) {
            mid = (l + r) / 2;
            if (!inBetween(y, ver[mid].sY, ver[mid].eY)) {
                if (y < ver[mid].sY)
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                break;
            }
        }
        if (inBetween(y, ver[mid].sY, ver[mid].eY)) {
            return ver[mid].len + abs(ver[mid].sY - y);
        }
    }
    if (hor.size() != 0) {
        int l = 0;
        int r = hor.size() - 1;
        int mid = (l + r) / 2;
        while (l <= r) {
            mid = (l + r) / 2;
            if (!inBetween(x, hor[mid].sX, hor[mid].eX)) {
                if (x < hor[mid].sX)
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                break;
            }
        }
        if (inBetween(x, hor[mid].sX, hor[mid].eX)) {
            return hor[mid].len + abs(hor[mid].sX - x);
        }
    }
    return 0;
}
int main() {

    int n, p;
    cin >> n >> p;
    int x0, y0;
    cin >> x0 >> y0;
    int prevX = x0;
    int prevY = y0;
    int x, y;
    vector<vector<Fence>> horizontal(1001);
    vector<vector<Fence>> vertical(1001);
    int sum = 0;
    for (int i = 0; i < p - 1; i++) {
        cin >> x >> y;
        Fence fen = {prevX, prevY, x, y, sum};
        if (x == prevX) vertical[x].push_back(fen);
        if (y == prevY) horizontal[y].push_back(fen);
        sum += abs(prevX - x) + abs(prevY - y);
        prevX = x;
        prevY = y;
    }

    Fence fen = {prevX, prevY, x0, y0, sum};

    if (x0 == prevX) vertical[x0].push_back(fen);
    if (y0 == prevY) horizontal[y0].push_back(fen);
    sum += abs(prevX - x0) + abs(prevY - y0);

    for (auto &row : vertical) {
        sort(row.begin(), row.end(), cmpV);
    }
    for (auto &row : horizontal) {
        sort(row.begin(), row.end(), cmpH);
    }
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int dist1 = compute(x1, y1, vertical[x1], horizontal[y1]);
        int dist2 = compute(x2, y2, vertical[x2], horizontal[y2]);
        int diff = abs(dist1 - dist2);
        if (sum - diff < diff) diff = sum - diff;
        cout << diff << endl;
    }

    return 0;
}