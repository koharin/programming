#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T; // T: 테스트케이스 수, n: 스티커 수
    int DP[2][100001];

    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int n;
        scanf("%d", &n);

        DP[0][0] = DP[1][0] = 0;

        for(int j=1; j<=n; j++)
            scanf("%d", &DP[0][j]);
        for(int j=1 ; j<=n; j++)
            scanf("%d", &DP[1][j]);
        
        //DP[0][1] = DP[0][1] + DP[1][0];
        //DP[1][1] = DP[0][0] + DP[1][1];

        for(int j=2; j<=n; j++){
            DP[0][j] = DP[0][j] + max(DP[1][j-1], DP[1][j-2]);
            DP[1][j] = DP[1][j] + max(DP[0][j-1], DP[0][j-2]);
        }

        printf("%d\n", max(DP[0][n], DP[1][n]));
    }

}