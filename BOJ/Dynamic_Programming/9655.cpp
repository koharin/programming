#include <iostream>

using namespace std;
/*
int solution(int N){
    int answer=1; // 현재 누구인지 홀수:SK, 짝수: CY

    while(N>0){
        if(N<3) N-=3;
        else N-=1;
        answer++; 
    }

    return answer;
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // N: 돌 개수
    int N; cin >> N;
    // 상근->창영 순서로 1개 또는 3개 돌을 가져감 
    // 돌 몇 개를 가져가든 홀수개면 홀수번쨰가 이기고, 짝수개면 짝수번쨰가 이기게 됨
    if(N % 2 == 0) cout << "CY" << endl;
    else cout << "SK" << endl;
    return 0;
}