#include <iostream>

using namespace std;

int main(){
    int n,k; cin >> n >> k;
    vector<int> cost(n,0);
    vector<int> DP(k+1,0);

    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    sort(cost.begin(), cost.end());
    //for(int n: cost) cout << n << endl;
    DP[0]=1;
    //DP[1]=1;
    //if(n>=2) DP[2]=2;
    for(int i=0; i<n; i++){
        for(int j=cost[i]; j<=k; j++){
            DP[j]+=DP[j-cost[i]];
        }
    }
    cout << DP[k] << endl;

    return 0;
}