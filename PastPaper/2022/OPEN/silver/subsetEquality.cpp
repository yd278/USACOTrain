#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> dp(262144);
    string s, t;
    cin >> s >> t;

    vector<int> cnt(18);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    for (char c : t) {
        cnt[c - 'a']--;
    }
    for (int i = 0; i < 18; i++) {
        if (cnt[i] == 0) dp[1 << i] = true;
    }
    vector<int> line;
    for (int i = 0; i < 18; i++) {
        for (int j = i + 1; j < 18; j++) {
            string ts = "";
            string tt = "";
            for (char c : s)
                if (c - 'a' == i || c - 'a' == j) ts += c;
            for (char c : t)
                if (c - 'a' == i || c - 'a' == j) tt += c;
            if (ts == tt) dp[1 << i | 1 << j] = true;
        }
    }


    int q;
    cin >> q;
    string sub;
    while(q--) {
        cin >> sub;
		if(sub.size()==1){
			cout<<(dp[1<<(sub[0]-'a')]?'Y':'N');
			continue;
		}
		bool res = true;
		for(int i = 0; i < sub.size(); i++){
			for(int j = i + 1; j < sub.size(); j++){
				int bi = sub[i] - 'a';
				int bj = sub[j] - 'a';
				res &= dp[1<<bi | 1<<bj];
			}
		}
		cout<<(res?'Y':'N');
    }
	cout<<endl;
    return 0;
}
