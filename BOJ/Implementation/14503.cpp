#include <iostream>
#include <queue>
#define MAX_NUM 50
using namespace std;
// 0(북), 1(동), 2(남), 3(서)
int N,M,r,c,d;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int room[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM];
int ans;

void Input(){
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> room[i][j];
    }
}

bool solution(){
    //queue< pair<int,int> > q;
    //q.push(make_pair(r,c));
    bool check=false;
    // Step 1.
    if(visited[r][c]==0) { ans++; visited[r][c]=1; } 
    
    // Step 2.
    //int nd=d;
    for(int i=0; i<4; i++){ // 계속 바라보는 방향 기준 반시계 방향 회전
        d=(d-1+4)%4;
        int nx=r+dx[d];
        int ny=c+dy[d];
        if(nx<=0 || ny<=0 && nx>=N-1 || ny>=M-1 || room[nx][ny]==1 || visited[nx][ny]==1) continue;
        check=true;
        r=nx;
        c=ny;
        //d=nd; // 있으면 반시계 회전
        break;            
        
    }
    // Step 3.
    if(!check){ 
        // Step 2. 청소되지 않은 빈 칸 없는 경우 
        // 바라보는 방향 유지하고(d는 유지) 한 칸 후진할 수 있으면(nd로 후진) 후진하고 1번 0->2, 2->0, 1->3, 3->1
        int nd=(d+2)%4;
        int nx=r+dx[nd], ny=c+dy[nd];
        if(nx>0 && ny>0 && nx<N-1 && ny<M-1 && room[nx][ny]==0){
            r=nx;
            c=ny;
            return true;
        }else{
            // 후진할 수 없으면 작동 종료 return false
            
            return false;
        }        
    }
    return true; 
}

int getAnswer(){
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(room[i][j]==0 && visited[i][j]) ans++;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Input();
    while(true){
        cout << r << "," << c << " d: " << d << endl;
        bool state=solution();
        if(!state) break;
    }
    cout << getAnswer() << endl;
    //cout << ans << endl;
    return 0;
}