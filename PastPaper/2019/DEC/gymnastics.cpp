#include <iostream>
using namespace std;

int ranks[21][11];  // ranks[i][j] 表示i号奶牛在j号课上的名次

int main() {
	#ifndef ONLINE_JUDGE
		freopen("gymnastics.in","r",stdin);
		freopen("gymnastics.out","w",stdout);
	#endif
    int k, n;
    int cow;
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cow;
            ranks[cow][i] = j;  // cow号奶牛在i号课上是第j名
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {  //不重复枚举pairs的做法，注意奶牛编号是从1开始的
            int sign =
                ranks[i][0] - ranks[j][0];  //记录第一节课谁比谁好，
                                            //负数表示i比j好，正数表示i比j差
            int flag = 1;
            for (int p = 1; p < k; p++) {
                if (sign * (ranks[i][p] - ranks[j][p]) < 0) { //用相乘来判断是否异号
                    flag = 0;
                    break;
                }
            }
			cnt += flag;
        }
    }
	cout<<cnt<<endl;
}