#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N; // N: 세준이를 생각해준 사람 수
    //vector< pair<int, int> > items(N+1, make_pair(0,0));
    int DP[101]={0,}; // DP[남은 체력] = 최대 기쁨
    int H[21];
    int J[21];

    scanf("%d", &N);

    for(int i=1; i<=N; i++) // 각각의 사람에게 인사를 할 때, 잃는 체력 순서대로 입력
        scanf("%d", &H[i]);
    
    for(int i=1; i<=N; i++) // 각각의 사람에게 인사를 할 때, 얻는 기쁨 순서대로 입력
        scanf("%d", &J[i]);

    for(int i=1; i<=N; i++){

        for(int j=100; j>H[i]; j--){
            DP[j] = max(DP[j], DP[j-H[i]] + J[i]);
        }
    }


    printf("%d\n", DP[100]);

    return 0;
}