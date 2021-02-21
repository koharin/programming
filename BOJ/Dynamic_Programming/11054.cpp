#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int S[N] = {}; int DP[N] = {}; int DP2[N] = {};

    for(int i=0; i<N; i++) scanf("%d", &S[i]);

    for(int i=0; i<N; i++){
        DP[i] = 1;
        for(int j=0; j<i; j++){
            if(S[i] > S[j]) DP[i] = max(DP[i], DP[j]+1);
        }        
    }
    for(int i=N-1; i>=0; i--){
        DP2[i] = 1;
        for(int j=N-1; j>i; j--){
            if(S[i] > S[j]) DP2[i] = max(DP2[i], DP2[j]+1);
        }        
    }

    int result=1;
    
    for(int i=0; i<N; i++){
        printf("DP[%d]: %d DP2[%d]: %d\n", i, DP[i], i, DP2[i]);
        result = max(result, DP[i] + DP2[i]-1);
    }
    
    printf("%d", result);
}