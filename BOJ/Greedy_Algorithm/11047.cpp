#include <stdio.h>
using namespace std;

int main(){
    int N,K, count=0; // N: 동전의 종류, K: 가치의 합
    scanf("%d %d", &N, &K);
    int A[N];

    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    for(int i=N-1; i>=0; i--){
        if(A[i] > K) continue;
        count += K / A[i];
        K %= A[i];
    }
    printf("%d\n", count);
}
