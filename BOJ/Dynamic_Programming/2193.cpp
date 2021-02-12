#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);

    long long  DP[N+1][2] = {0,}; // N == 90인 경우, 수가 크므로 long long 형
    
    DP[1][0] = 0; DP[1][1] = 1;
    
    for(int i=2; i<=N; i++){
        DP[i][0] = DP[i-1][0] + DP[i-1][1]; // 0일 때 1 또는 0이 오면 됨
        DP[i][1] = DP[i-1][0]; //1일 때 앞에는 항상 0이 와야 함
    }
    
    printf("%lld", DP[N][0] + DP[N][1]);
}