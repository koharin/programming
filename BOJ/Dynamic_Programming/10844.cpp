#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int DP[N+1][10] = {};

    for(int i=0; i<10; i++){
        DP[1][i] = 1; // 1_ 일 때 0 ~ 9 저장
    }
    for(int i=2; i <= N; i++){
        for(int j=0; j<10; j++){ // 0 ~ 9
            if(j == 0) DP[i][0] = DP[i-1][1]; // 뒷자리가 0일 때 앞은 1
            else if(j == 9) DP[i][9] = DP[i-1][8]; // 9가 올 때 이전은 8 또는 이후는 8
            else DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % 1000000000; // 1 ~ 8 의 경우, +1 수 또는 -1 수
        }
    }
    int sum=0;
    for(int i=1; i<10; i++){ // N일 때의 모든 경우의 수를 더해줌
        sum = (sum + DP[N][i]) % 1000000000;
    }
    printf("%d", sum % 1000000000);
    
}