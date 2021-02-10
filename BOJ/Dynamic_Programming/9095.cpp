#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int n;
        scanf("%d", &n);
        vector<int> DP(n);
        
        DP[0] = 1; DP[1] = 2; DP[2] = 4;
        
        for(int j=3; j<n; j++){
            DP[j] = DP[j-2] + DP[j-1] + DP[j-3];
        }
        
        printf("%d\n", DP[n-1]);
    }
}