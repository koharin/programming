#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    //vector<int> v[n];
    int DP[500][500]={0,};
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> DP[i][j];
        }
    }
    int answer=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0) DP[i][j]=DP[i][j]+DP[i-1][0];
            else if(j==i) DP[i][j]=DP[i][j]+DP[i-1][j-1];
            else DP[i][j]=DP[i][j]+max(DP[i-1][j-1], DP[i-1][j]);
            answer=max(answer,DP[i][j]);
        }
        
    }
    cout << answer << endl;

    return 0;
}