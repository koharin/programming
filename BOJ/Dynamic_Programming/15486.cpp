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
        // i일에서 일했을 때 그 일수 후 이익 업데이트
        if(i+T[i]-1<=N){
            // T일 지난 후 최댓값은 T번쨰 선택했을 때 값과 i-1일 때에허 현재 일했을 때
            DP[i+T[i]-1]=max(DP[i+T[i]-1], DP[i-1]+P[i]);
        }
        //i일에서의 max 업데이트.
        DP[i]=max(DP[i], DP[i-1]);
    }
    cout << DP[N] << endl;
    return 0;
}
// 1 선택하면 T[i]-1일 후에는, 즉 3일 후에는 이익이 10 DP[1+T[1]-1]=P[1] max=0
// 2 선택 시 DP[2+T[2]-1]=DP[6]=20 max=0
// 3 선택 시 DP[3+1-1]=10  max=10
// 4 선택 시 DP[4+1-1]=20 max= DP[i-1],DP[i]

// N일에서 최대 이익은 N일까지 최대 이익+N일에 일해서 번돈 or 기존에 DP[N] 구한 값