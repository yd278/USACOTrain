#include <iostream>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("whereami.in","r",stdin);
		freopen("whereami.out","w",stdout);
	#endif
    int n;
    string farms;
    cin >> n;
    cin >> farms;
    for (int k = 1; k <= n; k++) {
       
        int works = 1;
		 //寻找是否有k长的相等子序列
        for (int i = 0; i < n - k; i++) {  // i是第一段的起点
            if (!works) break;             //常数优化，降低用时
            for (int j = i + 1; j <= n - k; j++) {  // j是第二段的起点
                //判断[i,i+k], [j,j+k]是否相等
                int equalFlag = 1;
                for (int l = 0; l < k; l++) {
                    if (farms[i + l] != farms[j + l]) {
                        equalFlag = 0;
                        break;
                    }
                }
                
				if(equalFlag){
					works = 0;
					break;
				}
            }
        }
		if(works){
			cout<<k<<endl;
			return 0;
		}
    }
}