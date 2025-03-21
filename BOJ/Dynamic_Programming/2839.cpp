#include <iostream>

using namespace std;
int DP[5001]; // global 변수는 0으로 초기화됨
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    DP[3]=1; DP[5]=1; // 3kg은 1봉지, 5kg도 1봉지
    for(int i=6; i<=N; i++){
        // 이미 DP[i-3]가 있는 경우 업데이트
        if(DP[i-3]) DP[i]=DP[i-3]+1;
        // DP[i-3] 없으면 DP[i-5]+1로 업데이트, 있었으면 DP[i-3]로 업데이트된 DP[i-3]+1과 비교되는 것과 동일
        if(DP[i-5]) DP[i]= DP[i] ? (min(DP[i],DP[i-5]+1)) : DP[i-5]+1;
    }
    cout << (DP[N] ? DP[N] : -1) << "\n";
    return 0;
}
// i kg 만드는 경우=이전에 i-3kg 넣은 경우+1 또는 i-5kg개 넣은 경우+1