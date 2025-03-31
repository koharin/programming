#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_K 1000
#define MAX_R 70
#define MAX_C 70
#define EMPTY make_pair(-1,-1)

using namespace std;

int R,C,K;
// 출구 방향
int dx[]={-1,0,1,0}; // 북,동,남,서 
int dy[]={0,1,0,-1};
int answer; // 각 골렘의 정령이 도달할 수 있는 최하단 행 총합 저장
int forest[MAX_R+3][MAX_C]; // 허공에서 내려왔을 때 최종지점 맵 밖인지 확인 위해 2행 추가
bool isExit[MAX_R+3][MAX_C]; // 칸이 골렘의 출구인지

bool inRange(int x, int y){
    return x >= 3 && x < R+3 && y >= 0 && y < C; // +3(0,1,2 index) 나와있을 수 있으므로 3부터 유효
}
// 중심이 (x,y)인 경우, (x+1,y)

bool canGo(int x, int y){
    // 격자 안인지 && 다른 골렘 없는지
    if(x>=0 && x<R+3 && y>=0 && y<C && forest[x][y]==0) return true;
    else return false;
}
void reset(){
    for(int i=0; i<R+3; i++){
        for(int j=0; j<C; j++){
            forest[i][j]=0;
            isExit[i][j]=false;
        }
    }
}
// 정령이 움직일 수 있는 모든 범위 확인하고, 도달할 수 있는 최하단 행 반환
int bfs(int x, int y){
    int result=x; // 행 번호
    queue< pair<int,int> > q;
    int visit[MAX_R+3][MAX_C]={0,};
    q.push(make_pair(x,y));
    visit[x][y]=1;

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            // 골렘 내부(현재 forest[cx][cy]와 동일) || 골렘 탈출구에 위치 다른 골렘으로 옮겨감 (현재가 탈출구에 있고 인접이(nx,ny) 다른 골렘인 경우 다른 골렘으로 이동 가능)
            if(inRange(nx,ny) && visit[nx][ny]==0 && (forest[nx][ny]==forest[cx][cy] || (forest[nx][ny]!=0 && isExit[cx][cy]==true))){
                visit[nx][ny]=1;
                q.push(make_pair(nx,ny));
                // nx 중 가장 큰 값을 저장함
                result=max(result,nx);
            }
        }
    }
    return result;
}

void search(int x, int y, int d, int gol_num){ 

    // Step 1. 남쪽으로 한 칸 내려감
    if(canGo(x+2, y) && canGo(x+1, y-1) && canGo(x+1, y+1)) // x+1 이동이 유효하면 x+1
    {
        search(x+1,y,d,gol_num);
    }
    // Step 2. (1) 안 되면 서쪽 방향으로 회전하며 내려감 초기 중심(x,y) 기준 이동되는 좌표의 유효성 확인
    else if(canGo(x-1, y-1) && canGo(x,y-2) && canGo(x+1,y-1) && canGo(x+1, y-2) && canGo(x+2,y-1)){
        d=(d-1+4)%4;
        search(x+1,y-1,d,gol_num);
    }
    else if(canGo(x-1,y+1) && canGo(x,y+2) && canGo(x+1,y+1) && canGo(x+2,y+1) && canGo(x+1,y+2)){
        d=(d+1+4)%4;
        search(x+1,y+1,d,gol_num);
    }else{ // 움직일 수 없는 경우
        // 1. 골렘 동,서,남,북이 숲을 벗어나면 모든 골렘이 숲 빠져나감
        if(!inRange(x-1,y) ||  !inRange(x+1,y) || !inRange(x,y-1) || !inRange(x,y+1)){
            reset();
        }
        // 2. 아닌 경우 해당 골렘이 숲 안에 정착
        else{
            // 골렘 id를 적어서 업데이트
            forest[x][y]=gol_num;
            for(int i=0; i<4; i++){
                forest[x+dx[i]][y+dy[i]]=gol_num;
            }
            // 골렘 출구 기록
            isExit[x+dx[d]][y+dy[d]]=true;
            // 정령이 최고로 내려간 행의 위치 계산해서 answer에 더함
            answer += bfs(x,y)-3+1; // 계산 편의 위해 +2 맵으로 했지만 실제 forest는 행이 -2이므로 근데 1부터 시작이므로 +1?
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> K;

    for(int i=1; i<=K; i++){
        int c,d;
        cin >> c >> d;
        search(1,c-1,d,i);
    }
    cout << answer << "\n";
    return 0;
}
/*
    y    
  . O .
  O O O
x O O O
  . O .
  dx={-1,0,1,1,1,-1,0,1,1,1}
  dy={-1,-1,-1,-1,0,1,1,1,0,1}
*/