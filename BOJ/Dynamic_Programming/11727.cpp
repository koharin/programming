#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> DP(n);

    DP[0] = 1; DP[1] = 3;
    for(int i=2; i<n; i++){
        DP[i] = (DP[i-1] + DP[i-2] + DP[i-2]) % 10007;
    }
    printf("%d", DP[n-1]);

}