#include <iostream>
#include <vector>
#include <climits>
#define MAX_N 1000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> A(N+1,0);
    vector<int> DP(N+1,0);
    vector<int> check(N+1,0);
    int max_len=INT_MIN;
    
    for(int i=1; i<=N; i++) cin >> A[i];
    
    for(int i=1; i<=N; i++){
        DP[i]=1;
        for(int j=1; j<i; j++){
            if(A[i]>A[j]) DP[i]=max(DP[i], DP[j]+1);
        }
        // 가장 긴 수열을 구할 수 있도록 max_len 저장
        max_len=max(max_len,DP[i]);
    }
    int prev_index;
    cout << max_len << endl; // 가장 긴 길이
    // 각 DP 값은 인덱스에 해당함
     // DP를 역추적하면서 수열 구함
    for(int i=N; i>0; i--){
        //cout << DP[i] << " ";
        if(DP[i]==max_len){
            check[i]=1;
            //prev_index=DP[i]; // DP값이 길이값
            max_len--; 
            //break; // 여러 개인 경우 한 경우만 출력하도록 max는 하나만 
        }
    }
    //cout << endl;
    
    // 이전 인덱스 저장 후 -1인지 비교
    /*
    for(int i=N-1; i>=1; i--){
            if(DP[i]==(prev_index-1)){
                check[i]=1;
                prev_index--;
                continue;
            }
    }*/
    for(int i=1; i<=N; i++){
        if(check[i]) cout << A[i] << " ";
    }
    cout << "\n";
    return 0;
}