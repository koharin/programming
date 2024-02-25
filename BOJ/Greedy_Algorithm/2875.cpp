#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N,M,K;

    cin >> N >> M >> K;

    int team = min(N/2, M); // 최대 팀 수
    int result = min(team, (N+M-K)/3); // 대회 보낼 인원 뺐을 때 

    printf("%d\n", result);
    

    return 0;
}