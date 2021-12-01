#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
struct person {
    int time, index;
    bool operator<(const person &other) const { return time < other.time; }
} persons[1000];
int main() {
#ifndef ONLINE_JUDGE
    freopen("1223.in", "r", stdin);
    freopen("1223.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> persons[i].time;
        persons[i].index = i;
    }

    sort(persons, persons + n);
    long long wait = 0;
    long long  sum = 0;
    for (int i = 0; i < n; i++) {
        sum += wait;
        wait += persons[i].time;
        cout<<persons[i].index + 1<<" ";
    }
    cout<<endl;
    cout<<fixed<<setprecision(2)<<(double)sum / n<<endl;
    return 0;

}