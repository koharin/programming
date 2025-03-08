#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;

    for(int i=0; i<T; i++){
        int N; cin >> N;
        int zero=0, one=0;
        if(N==0){
            cout << 1 << " " << 0 << endl;
            continue;
        }
        if(N==1){
            cout << 0 << " " << 1 << endl;
            continue;
        }

        
        vector< pair<int, int> > DP(N+1);
        DP[0]=make_pair(1,0);
        DP[1]=make_pair(0,1);

        for(int k=2; k<=N; k++){
            DP[k]=make_pair(DP[k-1].first+DP[k-2].first, DP[k-1].second+DP[k-2].second);
            //cout << "DP[" << k << "]: (" << DP[k].first << "," << DP[k].second << ")" << endl;
        }
        
        cout << DP[N].first << " " << DP[N].second << endl;
    }

    return 0;
}
