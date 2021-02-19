#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int A[N] = {};
    int DP[N] = {};

    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    for(int i=0; i<N; i++){
        DP[i] = A[i];
        for(int j=0; j<i; j++){
            if(A[i] > A[j]) DP[i] = max(DP[i], DP[j]+A[i]);
        }
    }
    for(int i=0; i<N; i++) printf("DP[%d]: %d\n", i, DP[i]);
    printf("%d", *max_element(DP, DP+N));
    
}