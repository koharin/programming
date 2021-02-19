#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++){
        int n; 
        scanf("%d", &n);
        int num[2][n] = {0};
        int DP[2][n] = {0};
        
        
        for(int j=0; j<2; j++){
            for(int k=0; k<n; k++) scanf("%d", &num[j][k]);
        }
        
        DP[0][0] = num[0][0];
        DP[1][0] = num[1][0];
        DP[0][1] = num[0][1] + DP[1][0];
        DP[1][1] = num[1][1] + DP[0][0];
    
        for(int j=2; j<n; j++){
            DP[0][j] = num[0][j] + max(DP[1][j-1], DP[1][j-2]);
            DP[1][j] = num[1][j] + max(DP[0][j-1], DP[0][j-2]);
        }
        printf("%d\n", max(DP[0][n-1], DP[1][n-1]));
    }
}