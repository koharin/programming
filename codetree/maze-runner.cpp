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
    vector< pair<int,int> > participants;
    pair<int,int> exits;
    int total_move;
    int x,y,square_size;

    Sols(){
        total_move=x=y=square_size=0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) map[i][j]=0;
        }
    }
    void print(){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "exits: " << exits.first << "," << exits.second << endl;
        cout << "participants\n";
        for(int i=0; i<participants.size(); i++){
            cout << "(" << participants[i].first << "," << participants[i].second << ") ";
        }
        cout << endl;
    }
    int calc_distance(int cx, int cy){
        return abs(cx-exits.first)+abs(cy-exits.second);
    }
    void update_part(pair<int,int> src, pair<int,int> dst){
        for(int i=0; i<participants.size(); i++){
            pair<int,int> p = participants[i];
            if(p.first==src.first && p.second==src.second){
                participants[i].first=dst.first;
                participants[i].second=dst.second;
            }
        }
    }
    void step1(){
        // 상하좌우 최단거리로 이동 (출구까지)
        // 움직일 수 있는 칸>=2이면, 상하 먼저
        // 움직일 수 없으면, 움직이지 않음
        // 한 칸에 2명 이상 참가자 가능
        
        for(int i=0; i<participants.size(); i++){
            int cx=participants[i].first;
            int cy=participants[i].second;
            // 참가자가 출구면 이동하지 않음
            if(cx==exits.first && cy==exits.second) continue;
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
                    int nx=cx+dx[d];
                    int ny=cy+dy[d]; 
                    // 벽인건 빼줘야 함
                    if(nx<1 || ny<1 || nx>N || ny>N || map[nx][ny]!=0) continue;                   
                    if(calc_distance(cx+dx[d], cy+dy[d])==min_d){
                        participants[i].first=cx+dx[d];
                        participants[i].second=cy+dy[d];
                        break;
                    }
                }
                total_move++;
            }
        }
    }
    void get_square(){
        int size; // 어떤 크기일 때인지 알아야 하므로
        //bool e=false, par=false;
        // temp에다 participant 표시해놓고 있는지 찾기

        // 좌측상단이 (x,y)일 때 만들 수 있는 정사각형 늘려가면서 참가자 최소 1명, 출구 포함할 수 있는 정사각형 구하면 break(1x1일 땐 있을 수 없으므로 2x2부터)
        for(size=1; size<N; size++){
            for(int i=1; i<=N-size; i++){
                for(int j=1; j<=N-size; j++){
                    
                    // 좌하단
                    int x2=i+size;
                    int y2=j+size;
                    //cout << "(" << i << "," << j << "), (" << x2 << "," << y2 << ")\n";
                    // exit이 해당 정사각형 안에 없으면 continue -> exit
                    if(!(i<=exits.first && x2>=exits.first && j<= exits.second && y2>=exits.second)) continue;
                    // x와 y 범위 안에 참가자 있는지 확인
                    bool is_participant=false;
                    for(int p=0; p<participants.size(); p++){
                        // 범위 안에 있을 때
                        if(i<=participants[p].first && x2>=participants[p].first && j<=participants[p].second && y2>=participants[p].second){
                            if(!(participants[p].first==exits.first && participants[p].second==exits.second)){
                                is_participant=true;
                            }
                        }
                    }
                    if(is_participant){
                        // 좌측상단, 정사각형 크기 정보 업데이트
                        x=i;
                        y=j;
                        square_size=size;
                        return;
                    }
                    
                }
            }
        }
        
    }
    void rotate(){
        // 벽 있으면 내구도--
        for(int x1=x; x1<=x+square_size; x1++){
            for(int y1=y; y1<=y+square_size; y1++){
                if(map[x1][y1]!=0) map[x1][y1]--;
            }
        }
        //map을 temp에 복사
        int temp[MAX_N+1][MAX_N+1];
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) temp[i][j]=map[i][j];
        }
        // 90도 회전
        for(int x1=x; x1<=x+square_size; x1++){
            for(int y1=y; y1<=y+square_size; y1++){
                // x1,y1을 일단 좌측상단에 옮기고
                int ox=x1-x, oy=y1-y;
                // 좌측상단회전하면 (0,square_size+1)
                int rx=oy, ry=square_size+1-ox-1;
                // 일단 회전하면 x1,y1이면 y1,- 가 됨
                // 회전한 위치에 원래 값 넣어야 함
                temp[x+rx][y+ry]=map[x1][y1];
                // 범위 안에 있으면             
            }
        }
        // 원본에 복사
        for(int x1=x; x1<=x+square_size; x1++){
            for(int y1=y; y1<=y+square_size; y1++) map[x1][y1]=temp[x1][y1];
        }
        // 참가자 옮기기(범위 안에 있으면)
        
        for(int i=0; i<participants.size(); i++){
            int cx=participants[i].first;
            int cy=participants[i].second;
            // 이미 출구에 있어도 출구도 같이 움직이기 때문에 옮겨주기
            //이미 출구면 항상 출구와 같이 움직이므로 상관없음
            //if(participants[i].first==exits.first && participants[i].second==exits.second) continue;
            if(x<=cx && (x+square_size)>=cx && y<=cy && (y+square_size)>=cy){
                int ox=cx-x, oy=cy-y;
                // 좌측상단회전하면 (0,square_size+1)
                int rx=oy, ry=square_size+1-ox-1;
                participants[i].first=x+rx;
                participants[i].second=y+ry;             
            }
        }
        // 출구 옮기기
        if(x<=exits.first && (x+square_size)>=exits.first && y<=exits.second && (y+square_size)>=exits.second){
            int ox=exits.first-x, oy=exits.second-y;
            // 좌측상단회전하면 (0,square_size+1)
            int rx=oy, ry=square_size+1-ox-1;
            exits.first=x+rx;
            exits.second=y+ry;            
        }           
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
        int x,y;
        cin >> x >> y;
        sol->participants.push_back(make_pair(x,y));
        // -로 해서 이동거리를 로깅하고 더해서 abs로 하면 이동거리 합 구하기??
    }
    int ex,ey; cin >> ex >> ey;
    sol->exits=make_pair(ex,ey);

    while(K--){
        // Step 1. 참가자의 이동 (한 칸)
        //cout << "round " << K << endl;
        sol->step1();
        //cout << sol->total_move << endl;
        //sol->print();
        // 참가자가 출구 도달 시 즉시 탈출
        // 모든 사람이 출구 탈출했으면 종료
        bool all_escape=true;
        for(int i=0; i<sol->participants.size(); i++){
            // 출구는 계속 바뀌는데..?
            if(!(sol->participants[i].first==sol->exits.first && sol->participants[i].second==sol->exits.second)) all_escape=false;
        }
        if(all_escape) break;
        
        // Step 2. 미로의 회전
        // 한 명 이상 참가자&출구 포함한 가장 작은 정사각형 잡음
        sol->get_square(); // 좌측상단이 (i,j)일 때
        //cout << sol->x << ", " << sol->y << " size: " << sol->square_size << endl;
        // 해당 정사각형으로(좌측상단 x,y 크기 square_size+1) 회전
        sol->rotate();
        //sol->print();
        
    }
    cout << sol->total_move << "\n";
    cout << sol->exits.first << " " << sol->exits.second << "\n";
    return 0;
}

/*
r: x좌표,(행), c: y좌표(열)
좌상단: (1,1)
미로: 0(이동 가능한 칸), 1~9(벽, 값은 내구도. 회전할 때 내구도-=1, 내구도==0은 빈칸으로 변경) 출구(도달 시 탈출)
*/