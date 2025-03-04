#include <iostream>
#include <string>

using namespace std;
int DP[1001][1001]={0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int max=0;
    
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        for(int j=0; j<str.size(); j++) DP[i][j+1]=str[j]-'0';
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(DP[i][j]==1){
                DP[i][j]=min(min(DP[i-1][j], DP[i][j-1]),DP[i-1][j-1])+1;
                if(max<DP[i][j]) max=DP[i][j]; // update max length of square
            }
        }
    }
    cout << max*max << endl;
    
    return 0;
}