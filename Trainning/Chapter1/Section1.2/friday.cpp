/*
ID: dyh2191
LANG: C++14
TASK: friday
*/
#include <iostream>
using namespace std;
int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int leap(int year){
	if(year % 100 == 0)
		return (year % 400 == 0);
	return (year % 4 == 0);
}
int cnt[7];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("friday.in","r",stdin);
		freopen("friday.out","w",stdout);
	#endif
	int day = 5;
	int month = 0;
	int year = 1900;
	cnt[day]++;
	int n;
	cin>>n;
	while(year < 1900 + n){
		day += days[month];
		if(month == 1) day += leap(year);
		day %= 7;
		cnt[day]++;
		month++;
		if(month == 12){
			month = 0;
			year ++;
		}
	}
	cnt[day] --;
	for(int i = 5; i < 11; i++){
		cout<<cnt[i % 7]<<" ";
	}
	cout<<cnt[4]<<endl;
	return 0;

}
