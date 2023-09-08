#include <iostream>
//#include <algorithm>
using namespace std;

int main(){
    int N; // N: 세준이를 생각해준 사람 수
    //vector< pair<int, int> > items(N+1, make_pair(0,0));
    //vector< vector<int> > DP(N+1, vector<int>(100+1)); // DP[사람 순서][남은 체력] = 최대 기쁨
    int DP[21][101]={0,}; // DP[사람 순서][남은 체력] = 최대 기쁨
    //int DP[101]={0,};
    int H[21];
    int J[21];

    scanf("%d", &N);

    for(int i=1; i<=N; i++) // 각각의 사람에게 인사를 할 때, 잃는 체력 순서대로 입력
        scanf("%d", &H[i]);
    
    for(int i=1; i<=N; i++) // 각각의 사람에게 인사를 할 때, 얻는 기쁨 순서대로 입력
        scanf("%d", &J[i]);

    
    for(int i=1; i<=N; i++){

        for(int j=1; j<=100; j++){
            //DP[i][j] = max(DP[i-1][j], DP[i-1][j-cur_health] + cur_joy);
            if(j-H[i] > 0)
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-H[i]] + J[i]);
            else DP[i][j] = DP[i-1][j];
        }
        
    }
    
    /*
    for(int i=1; i<=N; i++){
        int cur_health = items[i].first;
        int cur_joy = items[i].second;

        for(int j=100; j>cur_health; j--){
            DP[j] = max(DP[j-1], DP[j-cur_health] + cur_joy);
        }
    }
    */
    printf("%d\n", DP[N][100]);
    //printf("%d\n", DP[100]);

    return 0;
}