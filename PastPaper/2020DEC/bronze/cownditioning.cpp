/*
Credit to 路策
Congratulations on his promotion to the silver div.
*/

#include <cstdio>
#define ABS(a) (a > 0 ? a : -a)
#define MAXN 100001
using namespace std; 

int A[MAXN], B[MAXN], D[MAXN], n, ans;  

int main(){
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) scanf("%d", &A[i]); 
    for (int i = 0; i < n; i++) scanf("%d", &B[i]); 
    for (int i = 0; i < n; i++) D[i] = A[i] - B[i]; 
    ans += ABS(D[0]); 
    for (int i = 1; i < n; i++){
        if (D[i - 1] < 0 && D[i] > 0) ans += D[i];  
        if (D[i - 1] > 0 && D[i] < 0) ans += -D[i]; 
        else if (D[i] >= 0 && D[i - 1] >= 0 && D[i] >= D[i - 1]) ans += D[i] - D[i - 1];
        else if (D[i] <= 0 && D[i - 1] <= 0 && D[i] <= D[i - 1]) ans += ABS(D[i]) - ABS(D[i - 1]); 
    }
    printf("%d", ans); 
}