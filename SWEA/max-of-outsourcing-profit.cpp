#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n; // n: 휴가 수
    // 최대 수익 = max(지금까지 누적 + t의 외주 했을 때DP[n-t], DP[remain])

    cin >> n;
    //vector<pair<int,int>> outsourcing;
    vector<int> DP(n+1,0);
    vector<int> T(n+1,0);
    vector<int> P(n+1,0);

    for(int i=1; i<=n; i++){
        int t, p; // t: 외주 작업 수행 완료 기한, p : 외주완료 시 수익
        cin >> t >> p;
        if((i+t-1)<=n){
            T[i] = t;
            P[i] = p;
        }
    }

    for(int i=1; i<=n; i++){
        // T일 지난 후 최대값 = max(i번째 외주 수행했을 때 T일 지난 후 최대값, i-1번째날까지 최대값+i번째날 외주 수익값)
        if((i+T[i]-1)<=n) DP[i+T[i]-1] = max(DP[i+T[i]-1], DP[i-1] + P[i]);
        DP[i] = max(DP[i], DP[i-1]);
        cout << "DP[" << i << "]: " << DP[i] << endl;
    }
    cout << DP[n] << endl;
    return 0;
}