#include <stdio.h>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    deque<int> DP(N+1, 0);

    for(int i=1; i<=N; i++){
        DP[i] = i; // 1로만 구성했을 때 개수로 초기화
        for(int j=1; j*j <= i; j++){
            DP[i] = min(DP[i], DP[i-j*j]+1);
        }
    }
    for(int i=1; i<=N; i++) printf("DP[%d]: %d\n", i, DP[i]);
    printf("%d", DP[N]);
    
}
