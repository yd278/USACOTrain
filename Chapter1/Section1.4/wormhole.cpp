/*
ID: dyh2191
LANG: C++14
TASK: wormhole
*/

#include <iostream>
using namespace std;

int x[13];
int y[13];
int out[13];  //预处理从该虫洞出来后会进入哪个虫洞，若没有，则-1
int in[13];  //生成从该虫洞进去后会从哪个虫洞出来（即生成配对）
int n;
int mark[13]; //进这个虫洞之后会不会出去 0：还未检查，-1：可以出去， 1：正在访问/ 不能出去。

int cnt = 0;

int check_rec(int x){
	if(x==-1) return -1;
	if(mark[x]==1)return 1;
	mark[x] = 1;
	return mark[x] = check_rec(out[in[x]]);
}
int check() {
    for(int i = 0; i < n; i++){
		mark[i] = 0;
	}
	for(int i = 0; i < n; i++){
		if(mark[i] == 0){
			int res = check_rec(i);
			if(res==1) return 1;
		}
	}
	return 0;
}

void generate(int x) {
    if (x == n) {
        cnt += check();
        return;
    }
    if (in[x] == -1) {
        for (int i = x + 1; i < n; i++) {
            if (in[i] == -1) {
                in[x] = i;
                in[i] = x;
                generate(x + 1);
                in[i] = -1;
                in[x] = -1;
            }
        }

    } else {
        generate(x + 1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    //预处理
    for (int i = 0; i < n; i++) out[i] = in[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (y[i] == y[j] && x[i] < x[j]) {
                if (out[i] == -1)
                    out[i] = j;
                else if (x[j] < x[out[i]])
                    out[i] = j;
            }
        }
    }

    generate(0);
    cout << cnt << endl;
}