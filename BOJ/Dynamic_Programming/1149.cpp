#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int cost[3];
    int house[1001][3]={0,};
    for(int i=1; i<=N; i++){
        // i번째가 r인 경우 -> i-1은 g 또는 i-1이 b
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0]=min(house[i-1][1], house[i-1][2]) + cost[0];
        house[i][1]=min(house[i-1][0], house[i-1][2]) + cost[1];
        house[i][2]=min(house[i-1][0], house[i-1][1]) + cost[2];
        
    }
    cout << min(house[N][0],min(house[N][1], house[N][2])) << endl;
}