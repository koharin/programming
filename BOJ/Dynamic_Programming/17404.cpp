#include <iostream>
#define INF 100000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int cost[1001][3];
    int DP[1001][3];
    int answer=INF;
    for(int i=1; i<=N; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    for(int i=0; i<3; i++){
        // 1번째가 각각 R,G,B일 때 2부터 N을 구함
        for(int m=0; m<3; m++){
            if(m==i) DP[1][m]=cost[1][m];
            else DP[1][m]=INF;
        }

        for(int j=2; j<=N; j++){
            
            DP[j][0]=min(DP[j-1][1],DP[j-1][2]) + cost[j][0];
            DP[j][1]=min(DP[j-1][0],DP[j-1][2]) + cost[j][1];
            DP[j][2]=min(DP[j-1][0],DP[j-1][1]) + cost[j][2];    
        }
        // N은 i일 때 제외하고 min을 구해야 함 
        for(int m=0; m<3; m++){
            if(m==i) continue;
            else answer=min(answer,DP[N][m]);
        }
    }
    
    cout << answer << endl;
    return 0;
}