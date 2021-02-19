#include <stdio.h>
#include <deque>
using namespace std;

int main(){
    int N, result=0;
    scanf("%d", &N);
    int A[N]={};
    int DP[N] = {};

    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    for(int i=0; i<N; i++){
        DP[i] = 1;
        for(int j=0; j<i; j++){
            if(A[i]>A[j]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        result=max(result, DP[i]);
    }
    printf("%d", result);
}