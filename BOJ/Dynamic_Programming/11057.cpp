#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N); // N: length of number

    int DP[N+1][10] = {};

    for(int i=0; i<10; i++) DP[1][i] = 1;

    for(int i=2; i<=N; i++){ // 자릿수
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){ // 0 ~ 9 수에 대한 경우
                DP[i][j] += DP[i-1][k];
            }
            DP[i][j] %= 10007;
        }
    }
    int sum=0;
    for(int i=0; i<10; i++){
        sum = (sum + DP[N][i]) % 10007; 
    }
    printf("%d", sum % 10007);
}