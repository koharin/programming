#include <iostream>
#include <queue>

using namespace std;
int M,N,H; 
int graph[100][100][100];
int visited[100][100][100];
queue< pair<int, pair<int, int> > > q;

int dz[]={0,0,0,0,-1,1};
int dx[]={-1,0,1,0,0,0};
int dy[]={0,-1,0,1,0,0};
int answer[100][100][100];

void search(){

    while(!q.empty()){
        int cz=q.front().first;
        int cx=q.front().second.first;
        int cy=q.front().second.second;
        q.pop();
        //visited[cz][cx][cy]=1;
        for(int i=0; i<6; i++){
            int nz=cz+dz[i];
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nz<0 || nz>=H || nx<0 || nx>=N || ny<0 || ny>=M || graph[nz][nx][ny]==-1) continue;
            if(answer[nz][nx][ny]>=0) continue; // 이미 처리한 토마토면 
            if(graph[nz][nx][ny]==0){
                q.push(make_pair(nz, make_pair(nx,ny)));
                //visited[nz][nx][ny]=1;
                graph[nz][nx][ny]=1;
                // 다음 토마토는 현재 토마토+1에 익음
                answer[nz][nx][ny]=answer[cz][cx][cy]+1;
                cout << "current: << " << graph[nz][nx][ny] << "answer[" << nz << "][" << nx << "][" << ny << "]: " << answer[nz][nx][ny] << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bool tomato=false;
    int ans=-1;

    cin >> M >> N >> H;

    for(int h=0; h<H; h++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++) {
                cin >> graph[h][i][j];
                
                if(graph[h][i][j]==0) {
                    tomato=true;
                    // 익어야 하는 토마토면 -1을 넣음
                    answer[h][i][j]=-1;
                }
                if(graph[h][i][j]==1) q.push(make_pair(h, make_pair(i,j)));
            }
        }
    }
    // 모두 익어있는 상태인 경우 (0이 없는 경우)
    if(!tomato){
        cout << 0 << endl;
        return 0;
    }

    search();

    for(int h=0; h<H; h++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++) {
                
                // 안 익은 토마토가 있으면
                if(answer[h][i][j]==-1){
                    cout << -1 << endl;
                    return 0;
                }
                ans=max(ans,answer[h][i][j]);
            }
        }
    }   

    cout << ans << endl;
    return 0;
}