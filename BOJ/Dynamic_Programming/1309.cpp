#include <iostream>
#define MAX_N 100000

using namespace std;
int cage[MAX_N][3];
int main(){
    int N; cin >> N;
    cage[0][0]=1; //선택 안하는 경우 
    cage[0][1]=1; // 0번 선택하는 경우 
    cage[0][2]=1; // 1번 선택하는 경우 
    for(int i=1; i<N; i++){
        cage[i][0]=(cage[i-1][0]+cage[i-1][1]+cage[i-1][2])%9901;
        cage[i][1]=(cage[i-1][0]+cage[i-1][2])%9901;
        cage[i][2]=(cage[i-1][0]+cage[i-1][1])%9901; // 현재 i번째 1번 선택은 이전에 선택 X 또는 0번 선택한 경우 
        
    }
    cout << (cage[N-1][0]+cage[N-1][1]+cage[N-1][2])%9901 << endl;
    return 0;
}
//N=1 DP[1][0]=1 DP[1][1]=1
// N=2 DP[2][0]=3 DP[2][1]=3
// N=3 DP[i][0]인 경우 DP[i-1][1] + 1? DP