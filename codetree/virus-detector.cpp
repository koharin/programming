#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,LDR,MBR; cin >> n;
    long long answer=n; // 중요
    vector<int> REST(n,0);
    
    for(int i=0; i<n; i++) cin >> REST[i];
    cin >> LDR >> MBR;

    for(int i=0; i<n; i++){
        REST[i]-=LDR;
        if(REST[i]<=0) continue;
        if(REST[i]%MBR==0) answer+=(REST[i]/MBR);
        else answer+=(REST[i]/MBR) + 1;
        //REST[i]/=MBR;
    }
    cout << answer << endl;
    return 0;
}