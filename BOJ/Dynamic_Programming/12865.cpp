#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,K;

    scanf("%d %d", &N, &K);
    vector< pair<int, int> > items(N+1,make_pair(0,0));
    vector< vector<int> > DP(N+1, vector<int>(K+1)); // [물건 번호][무게] = 최대 가치

    for(int i=1; i<=N; i++){
        scanf("%d %d", &items[i].first, &items[i].second);
    }

    for(int i=1; i<=N; i++){
        int weight = items[i].first;
        int value = items[i].second;
        for(int j=1; j<=K; j++){ // 최대 담을 수 있는 무게를 하나씩 늘려감
            if(j-weight >= 0) DP[i][j] = max(DP[i-1][j], DP[i-1][j-weight] + value);
            else DP[i][j] = DP[i-1][j]; // 현재 물건 무게가 더 크면 최대 가치는 이전 물건의 
        }
    }
    printf("%d\n", DP[N][K]);

    return 0;
}