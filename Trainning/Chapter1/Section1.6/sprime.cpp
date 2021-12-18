/*
ID: dyh2191
LANG: C++14
TASK: sprime
*/

#include <iostream>
using namespace std;
int e[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int prime(int x) { 
    if(x<2) return 0;
    if(x==2) return 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int sprime(int x, int depth){ //是s质数，返回-1，不是，返回depth
	if(x>9){
		int t = sprime(x/10,depth+1);
		if(t!=-1) return t;
	}
	if(prime(x)) return -1;
	return depth;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("sprime.in","r",stdin);
		freopen("sprime.out","w",stdout);
	#endif
	int n;
	cin>>n;
	int x = e[n-1];

	while(x<e[n]){
		int t = sprime(x,0);
		if(t == -1) {
			cout<<x<<endl;
			x++;
		}
		else x+= e[t];
	}
	return 0;
}