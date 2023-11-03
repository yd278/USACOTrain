#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> c, o, w;
    int n = s.length();
    c.resize(n + 1);
    o.resize(n + 1);
    w.resize(n + 1);
    for (int i = 0; i < n; i++) {
        c[i + 1] = c[i];
        o[i + 1] = o[i];
        w[i + 1] = w[i];
        if (s[i] == 'C')
            c[i + 1]++;
        else if (s[i] == 'O')
            o[i + 1]++;
        else if (s[i] == 'W')
            w[i + 1]++;
    }

	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int cc = c[b] - c[a-1];
		int co = o[b] - o[a-1];
		int cw = w[b] - w[a-1];
		cc %= 2;
		co %= 2;
		cw %= 2;
		if(cc==1 && co == 0 && cw == 0){
			cout<<'Y';
		}
		else if (cc == 0 && co == 1 && cw == 1){
			cout<<'Y';
		}else{
			cout<<'N';
		}
	}
	cout<<endl;
    return 0;
}
