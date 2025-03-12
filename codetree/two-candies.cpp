#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 10
#define MAX_M 10
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int graph[MAX_N][MAX_M];
int N,M; 
int visited[MAX_N][MAX_M][MAX_N][MAX_M];
int step[MAX_N][MAX_M][MAX_N][MAX_M];
pair<int,int> epos;

struct INFO{
    int rx,ry;
    int bx,by;
    int count; // 움직인 횟수
};

INFO start;

bool CheckRedFirst(int x_red,int y_red, int x_blue, int y_blue, int direction){
    switch(direction){
        case 0:
            return (y_red==y_blue && x_red<x_blue);
        case 1:
            return (y_red==y_blue && x_red>x_blue);
        case 2:
            return (x_red==x_blue && y_red<y_blue);
        case 3:
            return (x_red==x_blue && y_red>y_blue);
    }
}

// 1번으로 빨간색, 파란색 위치 바꿀 수 있음
int bfs(){
    int ans=-1;
    queue<INFO> q;
    // 초기 red, blue 방문표시 및 큐에 push
    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by]=1;
    step[start.rx][start.ry][start.bx][start.by]=0;
    
    while(!q.empty()){
        INFO cur=q.front(); q.pop();
        // 이동 횟수가 10보다 커지는 경우
        if(cur.count>10) break;
        // red 구슬만 탈출한 경우
        if(graph[cur.rx][cur.ry]=='O' && graph[cur.bx][cur.by]!='O'){
            ans=cur.count;
            break;
        }
        for(int i=0; i<4; i++){
            int n_rx=cur.rx, n_ry=cur.ry;
            int n_bx=cur.bx, n_by=cur.by;
            // red 구슬을 벽이나 exit일 때까지 한 방향으로 이동시킴
            int r_dist=0, b_dist=0;
            while(1){
                if(graph[n_rx][n_ry]!='#' && graph[n_rx][n_ry]!='O'){
                    n_rx += dx[i];
                    n_ry += dy[i];
                    r_dist++;
                }else{
                    if(graph[n_rx][n_ry]=='#'){
                        n_rx-=dx[i];
                        n_ry-=dy[i];
                        r_dist--;
                    }
                    break;
                }
            }
            // blue 구슬을 벽이나 exit일 때까지 한 방향으로 이동시킴
            while(1){
                if(graph[n_bx][n_by]!='#' && graph[n_bx][n_by]!='O'){
                    n_bx+=dx[i];
                    n_by+=dy[i];
                    b_dist++;
                }else{
                    if(graph[n_bx][n_by]=='#'){
                        n_bx-=dx[i];
                        n_by-=dy[i];
                        b_dist--;
                    }
                    break;
                }
            }
            // red 구슬과 blue 구슬이 겹칠 경우
            if(n_rx==n_bx && n_ry==n_by){
                // 동시에 나오면 안됨
                if(graph[n_rx][n_ry]!='O'){
                    // 이동 전(cur)과 비교해서 움직인 거리가 큰 구슬을 뒤로 이동시킴
                    if(r_dist>b_dist){
                        n_rx-=dx[i];
                        n_ry-=dy[i];
                    }else{
                        n_bx-=dx[i];
                        n_by-=dy[i];
                    }
                }
            }
            // 이동한 위치의 방문여부 확인
            if(visited[n_rx][n_ry][n_bx][n_by]) continue;
            visited[n_rx][n_ry][n_bx][n_by]=1;
            INFO next;
            next.rx=n_rx; next.ry=n_ry;
            next.bx=n_bx; next.by=n_by;
            next.count=cur.count+1;
            q.push(next);
        }

    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int answer=0;

    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<M; j++) {
            graph[i][j]=s[j];
            // 각 위치에 대한 좌표 저장
            if(s[j]=='B'){ start.bx=i; start.by=j; graph[i][j]='.'; }
            if(s[j]=='R') { start.rx=i; start.ry=j; graph[i][j]='.'; }
            if(s[j]=='O') { epos=make_pair(i,j); }
        }
    }
    start.count=0;
    cout << bfs() << endl;
    

    return 0;
}