#include <iostream>
#define MAX_NUM 500
#define MAX_H 10000

using namespace std;

long long N,M;
long long map[MAX_NUM][MAX_NUM];
long long visit[MAX_NUM][MAX_NUM];
long long dx[]={-1,1,0,0};
long long dy[]={0,0,-1,1};

// (M,N) 위치가 목표
long long search(int x, int y){
    if(x==M-1 && y==N-1) return 1; // 재귀적으로 호출된 후 최종 도달됐을 때 1은 경우의 수 한 가지를 의미
    if(visit[x][y]!=-1) return visit[x][y];
    // visit이 있는 경우는 이미 경로에 포함된 것으로 보지 않음 
        visit[x][y]=0;
        // 가능한 가짓수마다 재귀적으로 호출해서 최종 도달하는 가짓수 구할 수 있음
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
            // 다음이 더 작은 경우(재귀적으로 search 호출해서 반환된 결과값들을 더해 감)
            if(map[nx][ny]<map[x][y]) visit[x][y]+=search(nx,ny);
        }
    
    return visit[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++) { 
            cin >> map[i][j]; 
            visit[i][j]=-1; 
        }
    }
    cout << search(0,0) << "\n";
    return 0;
}