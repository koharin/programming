#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int A[n] = {}; int DP[n] = {};

    for(int i=0; i<n; i++){
        int num; scanf("%d", &A[i]);
    }

    DP[0] = A[0];
    for(int i=1; i<n; i++){
        DP[i] = A[i];
        DP[i] = max(DP[i], DP[i-1]+A[i]);
    }
    for(int i=0; i<n; i++) printf("DP[%d]: %d\n", i, DP[i]);

    
    printf("%d", *max_element(DP, DP+n));
}