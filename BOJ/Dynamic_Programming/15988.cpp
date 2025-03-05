#include <iostream>
#include <vector>
using namespace std;
int solution(int n){
    vector<long long> DP(1000001,0);
    DP[1]=1;
    DP[2]=2;
    DP[3]=4;
    if(n>=4){
        for(int i=4; i<=n; i++){
            DP[i]=(DP[i-3]+DP[i-2]+DP[i-1])%1000000009;
        }        
    }

    return DP[n];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    
    for(int i=0; i<T; i++){
        int n; cin >> n;
        cout << solution(n) << endl;
        
    }
    return 0;
}