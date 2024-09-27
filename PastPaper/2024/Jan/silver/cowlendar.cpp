#include <bits/stdc++.h>

#include <vector>

using namespace std;
bool check(vector<long long> &A, long long k) {
    set<long long> chk;
    for(auto a : A){
        chk.insert(a % k);
        if(chk.size()>3) return false;
    }
    return true;
}
int main() {

    int N;
    vector<long long> a;
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.resize(distance(a.begin(), last));

    if(a.size()<=3){
        long long m = a[0] / 4;
        cout<<(m+1)*m/2<<endl;
        return 0;
    }
    set<long long> Ls;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            long long diff = abs(a[i] - a[j]);
            for (long long k = 1; k * k <= diff; k++) {
                if (a[0] / k < 4) break;
                if (diff % k == 0) {
                    Ls.insert(k);
                    if (a[0] / (diff / k) >= 4) Ls.insert(diff / k);
                }
            }
        }
    }
    long long sum = 0;
    for (auto l : Ls) {
        if(check(a, l))sum+=l;
    }
    cout<<sum<<endl;
    return 0;
}
