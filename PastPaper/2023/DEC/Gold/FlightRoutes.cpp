#include <iostream>
#include <vector>
using namespace std;
bool count(vector<vector<bool>> const &parity,
           vector<vector<bool>> const &direct, int i, int j) {
    bool res = false;
    for (int k = 1; k < j; k++) {
        res ^= direct[i][i + k] && parity[i + k][i + j];
    }
    return res;
}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("FlightRoutes.in", "r", stdin);
//     freopen("FlightRoutes.out", "w", stdout);
// #endif
    int n;
    cin >> n;
    vector<vector<bool>> parity(n);
    for (auto &p : parity) p.resize(n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            char c;
            cin >> c;
            parity[i][j] = c == '1';
        }
    }
    vector<vector<bool>> direct(n);
    for (auto &d : direct) d.resize(n);

    for (int k = 1; k <= n - 1; k++) {
        for (int i = 0; i + k < n; i++) {
            bool inderect = count(parity, direct, i, k);
            direct[i][i + k] = inderect ^ parity[i][i + k];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++){
			if(direct[i][j])sum++;
		}
    }
	cout<<sum<<"\n";

    return 0;
}
