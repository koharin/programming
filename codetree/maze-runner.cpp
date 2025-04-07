#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAX_N 10
#define MAX_M 10
#define MAX_K 100

using namespace std;

int N,M,K;
// 상,하 우선
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

class Sols{
public:
    int map[MAX_N+1][MAX_N+1];
    vector< pair<int,int> > walls;
    struct PART{
        pair<int,int> pos;
        bool out;
    };
    vector<PART> participants;
    pair<int,int> exits;
    int total_move;

    Sols(){
        total_move=0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) map[i][j]=0;
        }
    }

    int calc_distance(int cx, int cy){
        return abs(cx-exits.first)+abs(cy-exits.second);
    }
    void update_part(pair<int,int> src, pair<int,int> dst){
        for(int i=0; i<participants.size(); i++){
            pair<int,int> p = participants[i].pos;
            if(p.first==src.first && p.second==src.second){
                participants[i].pos.first=dst.first;
                participants[i].pos.second=dst.second;
            }
        }
    }
    void step1(){
        // 상하좌우 최단거리로 이동 (출구까지)
        // 움직일 수 있는 칸>=2이면, 상하 먼저
        // 움직일 수 없으면, 움직이지 않음
        // 한 칸에 2명 이상 참가자 가능
    
        for(int i=0; i<participants.size(); i++){
            int cx=participants[i].pos.first;
            int cy=participants[i].pos.second;
            //vector< pair< int, pair<int,int> > > steps;
            // 현재 참가자 최단거리
            int min_d=calc_distance(cx,cy);
            int tx,ty;

            for(int d=0; d<4; d++){
                // 상,하,좌,우 거리 로깅
                
                int nx=cx+dx[d];
                int ny=cy+dy[d];
                if(nx<1 || ny<1 || nx>N || ny>N || map[nx][ny]!=0) continue;
                if(calc_distance(nx,ny)<min_d){
                    min_d=calc_distance(nx,ny);
                    tx=nx, ty=ny;
                }
            }
            // distance 기준 오름차순 정렬 후 가장 앞 칸으로 이동(만약 원래 칸이 min이었다면 이동하지 않을 것까지 고려 가능)
            // min_d인거 상,하,좌,우 순서로 찾음
            // 원래 좌표가 min_d면 그대로 놔둠
            if(min_d!=calc_distance(cx,cy)){ 
                for(int d=0; d<4; d++){
                    // 한 번 업데이트하고 끝냄
                    if(calc_distance(cx+dx[d], cy+dy[d])==min_d){
                        participants[i].pos.first=cx+dx[d];
                        participants[i].pos.second=cy+dy[d];
                        break;
                    }
                }
                total_move++;
            }
            // exit 도달 여부 확인
            if(participants[i].pos.first==ex && participants[i].pos.second==ey){
                participants[i].out=true;
            }
        }
    }
    void step2(int x, int y){
        int size,i,j; // 어떤 크기일 때인지 알아야 하므로
        bool e=false, par=false;
        // temp에다 participant 표시해놓고 있는지 찾기
        int temp[MAX_N][MAX_N];
        for(int m=1; m<=N; m++){
            for(int n=1; n<=N; n++){
                temp[m][j]=map[m][n];
            }
        }
        for(int m=0; m<participants.size(); m++){
            temp[participants[i].pos.first][participants[i].pos.second]=-1;
        }
        // 좌측상단이 (x,y)일 때 만들 수 있는 정사각형 늘려가면서 참가자 최소 1명, 출구 포함할 수 있는 정사각형 구하면 break(1x1일 땐 있을 수 없으므로 2x2부터)
        for(size=1; size<N; size++){
            for(i=x; i<=x+size; i++){
                for(j=y; j<=y+size; j++){
                    if(i==ex && j==ey) e=true;
                    if(temp[i][j]==-1) par=true;
                    if(e==true && par==true) {
                        
                        break;
                    }
                    
                }
            }
        }
        // 둘 다 들어있을 때의 좌측상단과 size 크기
        cout << "upper left: " << i << "," << j << " size: " << size << endl;
        // 선택된 정사각형은 시계방향 90도 회전, 그 안에 벽은 내구도 1 깎음
        // 벽이 있으면 내구도--
        // 참가자도 돌려야 함
        // exit도 돌려야 함
        // 첫 줄
        for(int m=0,n=size; m<=size; m++,n--){
            // temp가 -1이었으면, 
            map[i+0][j+m]=temp[i+n][j+0];
            if(temp[i+n][j+0]==-1){
                update_part(make_pair(i+n, j+0), make_pair(i+0, j+m));
                map[i+0][j+m]=0; // 빈 칸으로 만들어주기 (참가자 있는 자리는 빈 칸임)
            }
            if(map[i+0][j+m]!=0){
                // 벽이면 내구도--
                
            }
        }
        // 옆
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Sols* sol=new Sols();

    // inputs
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) {
            cin >> sol->map[i][j];
            if(sol->map[i][j]!=0) sol->walls.push_back(make_pair(i,j));
        }
    }
    for(int i=0; i<M; i++){
        sol->PART part;
        int x,y;
        cin >> x >> y;
        part.pos=make_pair(x,y);
        part.out=false;
        sol->participants.push_back(part);
        // -로 해서 이동거리를 로깅하고 더해서 abs로 하면 이동거리 합 구하기??
    }
    int ex,ey; cin >> ex >> ey;
    sol->exits=make_pair(ex,ey);

    while(K--){
        // Step 1. 참가자의 이동 (한 칸)
        sol->step1();
        cout << sol->total_move << endl;
        // 참가자가 출구 도달 시 즉시 탈출
        break;
        // Step 2. 미로의 회전
        // 한 명 이상 참가자&출구 포함한 가장 작은 정사각형 잡음
        for(int i=1; i<=N; i++){ // r좌표 작은 것 우선
            for(int j=1; j<=N; j++){ // r 동일하면 c좌표 작은 것 우선
                // 한 명 이상 참가자&출구 포함한 가장 작은 정사각형 찾기
                //1x1 or 2x2 or 3x3
                sol->step2(i,j); // 좌측상단이 (i,j)일 때
            }
        }
    }
    return 0;
}

/*
r: x좌표,(행), c: y좌표(열)
좌상단: (1,1)
미로: 0(이동 가능한 칸), 1~9(벽, 값은 내구도. 회전할 때 내구도-=1, 내구도==0은 빈칸으로 변경) 출구(도달 시 탈출)
*/