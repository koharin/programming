#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    deque<int> P(N+1,0);
    deque<int> DP(N+1,0);

    for(int i=1; i<=N; i++) scanf("%d", &P[i]);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            DP[i] = max(DP[i], DP[i-j]+P[j]); //초기 DP[i]=0
        }
        printf("DP[%d]: %d\n", i, DP[i]);
    }
    printf("%d", DP[N]);    
}