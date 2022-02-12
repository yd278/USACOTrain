#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 

vector<int> S, I; map<int, int> V; int n, s, k, ans; 

int main(){
    #ifndef ONLINE_JUDGE
        freopen("2.in", "r", stdin); 
        freopen("2.out", "w", stdout); 
    #endif 
    scanf("%d %d", &n, &k); 
    for (int i = 0; i < n; i++){
        scanf("%d", &s); 
        if (!V[s / 12]) S.push_back(s / 12); 
        V[s / 12] = 1; 
    }
    ans = S.size() * 12; 
    S.push_back(-1);
    sort(S.begin(), S.end()); 
    for (int i = 1; i < S.size(); i++) I.push_back(S[i] - 1 - S[i - 1]); 
    sort(I.begin(), I.end()); 
    for (int i = 0; i < S.size() - k; i++) ans += I[i] * 12; 
    printf("%d", ans); 
}