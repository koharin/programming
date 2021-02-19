#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int G[n] = {0};
    int DP[n] = {0};
    
    for(int i=0; i<n; i++) scanf("%d", &G[i]);
    for(int i=0; i<2; i++){
        if(i==0) DP[i] = G[i];
        else DP[i] = G[i] + G[i-1];
    }
    for(int i=2; i<n; i++){
        DP[i] = max(G[i] + G[i-1] + DP[i-3], G[i] + DP[i-2]);
        DP[i] = max(DP[i-1], DP[i]);
    }
    
    printf("%d", DP[n-1]);
}