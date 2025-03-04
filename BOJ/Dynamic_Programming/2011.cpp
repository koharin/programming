#include<iostream>
#include<vector>

using namespace std;

int main(){
    string code;
    cin >> code;
    int len=code.size();
    cout << "len: " << len << endl;
    vector<int> DP(len+1);
    DP[0]=1;


    for(int i=1; i<=len; i++){
        int one=code[i]-'0';
        int two=(code[i-1]-'0')*10+one;

        if(one>=1 && one<=9) DP[i]=(DP[i-1]+DP[i])%1000000;
        cout << "DP[" << i << "]: " << DP[i] << endl;
        if(i==1) continue;
        if(two>=10 && two <=26) DP[i]=(DP[i-2]+DP[i])%1000000;
        cout << "DP[" << i << "]: " << DP[i] << endl;
    }

    cout << DP[len] << endl;

    return 0;
}