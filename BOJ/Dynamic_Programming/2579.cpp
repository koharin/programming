#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int A[n] = {};
    int DP[n] = {};

    for(int i=0; i<n; i++) scanf("%d", &A[i]);

    DP[0] = A[0];
    DP[1] = max(A[1], A[0] + A[1]);
    DP[2] = max(A[1] + A[2], A[0] + A[2]);

    for(int i=3; i<n; i++){
        DP[i] = max(DP[i-2] + A[i], DP[i-3] + A[i-1] + A[i]);
    }
    for(int i=0; i<n; i++) printf("DP[%d]: %d\n", i, DP[i]);
    printf("%d", DP[n-1]); // 마지막은 항상 포함이므로
}