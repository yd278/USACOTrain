/*
ID: dyh2191
LANG: C++14
TASK: milk3
*/

#include <iostream>
#include <vector>
using namespace std;
#define MAXN 194481

int Ca, Cb, Cc;
inline int encode(int a, int b, int c) { return a * 441 + b * 21 + c; }
int possible[21];
int visited[MAXN];
vector<int> ans;
void dfs(int a, int b, int c) {
    int state = encode(a, b, c);
    if (visited[state]) return;
    visited[state] = 1;
    if(a==0)possible[c] = 1;

    int capacity;
    if (a) {
        // a to b;
        capacity = Cb - b;
        if (capacity >= a)
            dfs(0, b + a, c);
        else
            dfs(a - capacity, Cb, c);

        // a to c;
        capacity = Cc - c;
        if (capacity >= a)
            dfs(0, b, c + a);
        else
            dfs(a - capacity, b, Cc);
    }
    if (b) {
        capacity = Ca - a;
        if (capacity >= b)
            dfs(a + b, 0, c);
        else
            dfs(Ca, b - capacity, c);

        capacity = Cc - c;
        if (capacity >= b)
            dfs(a, 0, c + b);
        else
            dfs(a, b - capacity, Cc);
    }
    if (c) {
        capacity = Ca - a;
        if (capacity >= c)
            dfs(a + c, b, 0);
        else
            dfs(Ca, b, c - capacity);

        capacity = Cb - b;
        if (capacity >= c)
            dfs(a, b + c, 0);
        else
            dfs(a, Cb, c - capacity);
    }

}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("milk3.in","r",stdin);
		freopen("milk3.out","w",stdout);
	#endif
	cin>>Ca>>Cb>>Cc;
	dfs(0,0,Cc);
	for(int i = 0; i <= Cc; i++){
		if(possible[i]) ans.push_back(i);
	}
	for(int i = 0; i < ans.size() - 1; i++){
		cout<<ans[i]<<" ";
	}
	cout<<*ans.rbegin()<<endl;
}