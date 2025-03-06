#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    vector< vector<long long> > DP(10001,vector<long long>(4,0));
    DP[1][1]=1;
    DP[2][1]=1;
    DP[3][1]=1;
    DP[2][2]=1; // 2로 2만드는 경우=1가지
    DP[3][2]=1; // 2로 3 만드는 경우=1가지
    DP[3][3]=1; // 3으로 3 만드는 경우 =1가지
    for(int i=4; i<=n; i++){
        // 1로만 이루어진 경우의 수
        DP[i][1]=1; 
        // 1과 2로 이루어진 경우의 수
        DP[i][2]=DP[i-2][1]+DP[i-2][2];
        // 1,2,3으로 이루어진 경우의 수
        DP[i][3]=DP[i-3][1]+DP[i-3][2]+DP[i-3][3];

    }
    return DP[n][1]+DP[n][2]+DP[n][3];     
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    for(int i=0; i<T; i++){
        int n; cin >> n;
        cout << solution(n) << endl;
    }

    return 0;
}