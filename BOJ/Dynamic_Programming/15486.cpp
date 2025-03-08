#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    vector<int> T(N+1,0);
    vector<int> P(N+1,0);
    vector<int> DP(N+1,0);
    for(int i=1; i<=N; i++){
        cin >> T[i] >> P[i];
    }
    for(int i=1; i<=N; i++){
        // i번째 선택했을 때가 N 이하인 경우
        if(i+T[i]-1<=N){
            // T일 지난 후 최댓값은 i번쨰 선택했을 때 값과 i-1일 때 값 중 최댓값으로
            DP[i+T[i]-1]=max(DP[i+T[i]-1], DP[i-1]+P[i]);
        }
        //아닌 경우 i-1이나 i 중에 선택
        DP[i]=max(DP[i], DP[i-1]);
    }
    cout << DP[N] << endl;
    return 0;
}