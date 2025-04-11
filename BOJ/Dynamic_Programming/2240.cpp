#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
#define MAX_T 1000
#define MAX_W 30
#define MAX_POS 2
using namespace std;

int T,W;
int order[MAX_T+1];
int DP[MAX_POS+1][MAX_W+1][MAX_T+1];

int solution(){
    // 항상 1번에서 시작함
    DP[1][W][0]=0;
    for(int t=0; t<T; t++){ // 주어진 시간 동안 진행
        for(int cnt=0; cnt<=W; cnt++){ // cnt: 남은 움직임 횟수
            for(int pos=1; pos<=2; pos++){
                // 다음 위치는 t+1일 때
                if(DP[pos][cnt][t]>=0){
                    int npos=order[t+1];
                    if(pos==npos){ // 현재가 다음에 떨어질 위치일 때
                        DP[pos][cnt][t+1]=DP[pos][cnt][t]+1; // 다음 시간엔 자두 받음
                    }else{ // 다음에는 다른 위치에 떨어질 때
                        // cnt가 있으면 이동함
                        if(cnt!=0){
                            // 다음 위치에서는 이전에 움직여서 받은 경우이거나, 아닌 경우 
                            DP[npos][cnt-1][t+1]=max(DP[npos][cnt-1][t+1], DP[pos][cnt][t]+1);
                        }
                        // 이동 안함 (다음은 자두 못받으므로 현재 위치에서 개수를 넣음)
                        DP[pos][cnt][t+1]=DP[pos][cnt][t];
                    }
                }
            }
        }
    }
    // t가 T-1일 때 가장 큰 값을 찾음
    int ans=INT_MIN;
    for(int pos=1; pos<=2; pos++){
        // w가 없어서 못움직이는 경우 
        for(int t=1; t<=T; t++){
            ans=max(ans,DP[pos][0][t]);
        }
        // w가 있는 경우 T까지 움직였을 때 값 비교
        for(int cnt=0; cnt<=W; cnt++) ans=max(ans, DP[pos][cnt][T]);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T >> W;
    for(int i=1; i<=T; i++) {
        cin >> order[i];
    }
    memset(DP, -1, sizeof(DP));
    cout << solution() << "\n";
    return 0;
}
// i번째가 1에 있을 때 i-1은 1번 또는 2번
// i번째가 2에 있을 때 i-1은 1번 또는 2번
// DP[pos][cnt][time]=value
// 위치(1 또는 2) 남은 이동 수 현재 시간 = 자두 최대 개수
// 현재 위치에서 떨어지는 경우 다음 시간에는 DP[pos][cnt][time+1]=DP[pos][cnt][time]+1 현재 시간에서 자두 주음
// 현재 위치에서 떨어지지 않는 경우 자리 바꿈 DP[pos+1][cnt-1][time+1]=max(DP[pos+1][cnt-1][time+1], DP[pos][cnt][time+1])
// 현재 위치에서 떨어지지 않는 경우 자리 바꾸지 않음 cnt가 없는 경우 