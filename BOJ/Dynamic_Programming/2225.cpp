#include <stdio.h>

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    
    int DP[N+1][K+1] = {0,};
    for(int i=1; i<=N; i++) DP[i][1] = 1; // N = i, K = 1일 때 모든 N에 대해서 항상 1
    for(int i=1; i<=K; i++) DP[1][i] = i;

    for(int i=2; i<=N; i++){
        for(int j=2; j<=K; j++){
            DP[i][j] = (DP[i-1][j] + DP[i][j-1]) % 1000000000;
            printf("DP[%d][%d]: %d\n", i, j, DP[i][j]);
        }
    }
    printf("%d", DP[N][K]);
    
}