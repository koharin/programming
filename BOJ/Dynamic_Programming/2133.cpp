#include <stdio.h>
#include <deque>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    deque<int> DP(N+1, 0);
    DP[0] = 1;
    DP[2] = 3;
    if(N%2 !=0 ) DP[N] = 0; // N == 홀수

    // N == 짝수
    for(int i=4; i<=N; i+=2){
        DP[i] = DP[i-2]*3;
        for(int j=i-4; j >= 0; j -= 2) DP[i] += DP[j]*2;

    }
    for(int i: DP) printf("%d\n", i);
    printf("%d", DP[N]);

}