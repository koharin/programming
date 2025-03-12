#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> DP(n+1,0);
    // DP[0]=0 DP[1]=1 DP[2]=3
    DP[0]=1;
    DP[1]=1;
    if(n>=2){
        for(int i=2; i<=n; i++){
            DP[i]=(DP[i-1]+DP[i-2]+1)%1000000007;
        }
    }
    cout << DP[n] << endl;

    return 0;
}