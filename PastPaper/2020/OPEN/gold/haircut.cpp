#include <iostream>
#include <vector>
using namespace std;
long long tree[100005];
long long n;
vector<int>pos[100005];
long long lowbit(long long x){
	return x & -x;
}

long long query(long long i){
	if(i==-1)return 0; 
	long long sum = 0;
	while(i){
		sum += tree[i];
		i -= lowbit(i);
	}
	return sum;
}

void add(long long i){
	while(i<=n){
		tree[i]++;
		i+=lowbit(i);
	}
}
long long pre[100005];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("haircut.in","r",stdin);
		freopen("haircut.out","w",stdout);
	#endif
	cin>>n;
	long long a;
	for(int i = 0; i < n; i++){
		cin >>a;
		pos[a].push_back(i);
		a = n-a+1;
		add(a);
		pre[i] = query(a-1);
	}
	long long sum = 0;
	for(long long i = 0;i<n;i++){
		cout<<sum<<endl;
		for(long long k : pos[i]){
			sum+=pre[k];
		}
	}
	return 0;

}