#include <bits/stdc++.h>

using namespace std;
vector<int> a = {4, 2, 8, 5, 7, 1};
bool cmp2(int a, int b){
    return a > b;
}
int main() {
    freopen("sort.out", "w", stdout);
    // your code below
    sort(a.begin(),a.end());

    // your code above
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
}