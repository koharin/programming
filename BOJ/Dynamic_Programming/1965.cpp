#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> box(n+1,0);
    vector<int> DP(n+1,0);    
    for(int i=1; i<=n; i++) cin >> box[i];
    int max_len=INT_MIN;
    for(int i=1; i<=n; i++){
        DP[i]=1; // 현재 기준으로 시작했을 때 1
        for(int j=1; j<i; j++){ // i 이전까지 가장 긴 걸 찾음
            if(box[i]>box[j]) DP[i]=max(DP[i],DP[j]+1);

        }
        max_len=max(max_len, DP[i]);
    }
    cout << max_len << endl;
    return 0;
}