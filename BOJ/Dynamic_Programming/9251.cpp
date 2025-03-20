#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s1,s2;
    cin >> s1; s1="0"+s1;
    cin >> s2; s2="0"+s2;
    int DP[1001][1001]={0,};
    
    for(int i=1; i<s1.size(); i++){
        for(int j=1; j<s2.size(); j++){
            if(s1[i]==s2[j]) DP[i][j]=DP[i-1][j-1]+1;
            else DP[i][j]=max(DP[i-1][j], DP[i][j-1]);
        }
    }
    cout << DP[s1.size()-1][s2.size()-1] << "\n";

    return 0;
}