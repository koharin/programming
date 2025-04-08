#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 100000

using namespace std;

int DP[6]; // max일 때 0,1,2  min일 때 0,1,2가 차례로 0~5
//int DP2[MAX_N+1][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N;
    int max_value=INT_MIN;
    int min_value=INT_MAX;
    cin >> N;

    int a,b,c;
    cin >> a >> b >> c;
    DP[0]=a, DP[1]=b, DP[2]=c;
    DP[3]=a, DP[4]=b, DP[5]=c;
    for(int i=2; i<=N; i++){
        cin >> a >> b >> c;
        int temp_0=DP[0];
        int temp_1=DP[1];
        int temp_2=DP[2];
        int temp_3=DP[3];
        int temp_4=DP[4];
        int temp_5=DP[5];
        DP[0]=max(temp_0, temp_1) + a;
        DP[1]=max(temp_0, max(temp_1, temp_2)) + b;
        DP[2]=max(temp_1, temp_2) + c;
        DP[3]=min(temp_3, temp_4) + a;
        DP[4]=min(temp_3, min(temp_4, temp_5)) + b;
        DP[5]=min(temp_4, temp_5) + c; 
    }
    cout << max(DP[0], max(DP[1], DP[2])) << " " << min(DP[3], min(DP[4], DP[5])) << "\n";
    
    return 0;
}
// 다음줄-바로 아래 수이거나 바로 아래수와 붙어 있는 수로 
// [0]이면 이전이 [0]이거나 [1]만 가능
// [1]이면 이전이 [0],[1] [2]만 가능
// [2]면 이전이 [1],[2] 가능
// DP[i][j]=현재가 i
// DP[1]이면 최대 점수는 inputs[1][j]에 위치한 점수