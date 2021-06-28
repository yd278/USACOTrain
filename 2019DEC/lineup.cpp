#include <iostream>
using namespace std;
//先排好字典序方便到时候直接用数字处理
string names[8] = {"Beatrice", "Belinda", "Bella",     "Bessie",
                   "Betsy",    "Blue",    "Buttercup", "Sue"};

int n;
struct rel {
    int x, y;
} rels[8];

rel read() {
    rel res;
    string name;
    cin >> name;
    for (int i = 0; i < 8; i++) {
        if (name == names[i]) res.x = i;
    }
    cin >> name;  // must
    cin >> name;  // be
    cin >> name;  // milked
    cin >> name;  // beside
    cin >> name;

    for (int i = 0; i < 8; i++) {
        if (name == names[i]) res.y = i;
    }
    return res;
}

int seq[8];
int used[8];
int check() {  //检查目前的x头牛是否满足要求

    //提取出8头牛的位置
    int index[8];
    for (int i = 0; i < 8; i++) {
        index[seq[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (abs(index[rels[i].x] - index[rels[i].y]) != 1) return 0;
    }
    return 1;
}
int dfs(int x) {  //递归枚举第x个挤奶的牛是几号, 返回1表示找到了
    if (x == 8) {
        if (check()) {
            for (int i = 0; i < 8; i++) {
                cout << names[seq[i]] << endl;
            }
            return 1;
        } else {
            return 0;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (!used[i]) {
            seq[x] = i;
            used[i] = 1;
            if (dfs(x + 1)) return 1;
            used[i] = 0;
            seq[x] = 0;  //没必要，但是写了对称好看（
        }
    }
    return 0;
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("lineup.in","r",stdin);
		freopen("lineup.out","w",stdout);
	#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        rels[i] = read();
    }
    dfs(0);
	return 0;
}
