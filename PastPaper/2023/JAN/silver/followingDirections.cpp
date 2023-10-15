#include <bits/stdc++.h>
using namespace std;

int calc(vector<vector<int>> &size, vector<int> &costR, vector<int> &costB) {
    int ans = 0;
    int n = size.size() - 1;
    for (int i = 0; i < n; i++) {
        ans += costR[i] * size[i][n];
        ans += costB[i] * size[n][i];
    }
    return ans;
}

void relink(int x, int y, vector<vector<int>> &size, vector<vector<char>>&signpost, int direction){
	int tx,ty;
	int n = signpost.size();
	if(signpost[x][y]=='D')tx = x+1, ty = y;
	else ty = y+1, tx = x;
	while(tx < n && ty < n){
		size[tx][ty] += size[x][y] * direction;
		if(signpost[tx][ty] == 'D') tx++;
		else ty++;
	}
	size[tx][ty] += size[x][y] * direction;
}
int main() {

    int n;
    cin >> n;
    vector<vector<int>> size(n + 1);
    vector<vector<char>> signpost(n);
    for (auto &row : signpost) row.resize(n);
    for (auto &row : size) row.resize(n + 1);
    vector<int> costR(n);
    vector<int> costB(n);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            size[i][j]++;
            cin >> signpost[i][j];
            if (signpost[i][j] == 'R')
                size[i][j + 1] += size[i][j];
            else
                size[i + 1][j] += size[i][j];
        }
        cin >> costR[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> costB[i];
    }

    cout << calc(size, costR, costB) << endl;

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
		x--;y--;
		relink(x,y,size,signpost,-1);
		if(signpost[x][y] =='D') signpost[x][y] = 'R';
		else signpost[x][y] = 'D';
		relink(x,y,size,signpost,1);
		cout<<calc(size,costR,costB)<<endl;
    }
    return 0;
}
