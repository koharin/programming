#include <iostream>
#include <queue>
#define MAX_N 20
#define MAX_M 1000
using namespace std;

int n,m;
// 상(0)하(1)좌(2)우(3)
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

class Sols{
public:
    int matrix[MAX_N+1][MAX_N+1];
    int score;
    int cube[6]={1,6,5,2,4,3}; // 0(위) 1(아래) 2(상) 3하 4좌 5우
    int cur_x, cur_y, cur_d; // 상 (0) 하(1) 좌(2) 우(3)

    Sols(){
        score=0;
        cur_x=1, cur_y=1;
        cur_d=3; // 초기엔 3
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++) matrix[i][j]=0;
        }
    }
    void print(){
        cout << "current pos: (" << cur_x << "," << cur_y << ") dir: " << cur_d << endl;
        cout << "cube: ";
        for(int i=0; i<6; i++) cout << cube[i] << " ";
        cout << "\n score: " << score << endl;
    }
    void move(){
        // 이동하는 칸이 유효한지 먼저 확인
        int nx=cur_x+dx[cur_d];
        int ny=cur_y+dy[cur_d];
        if(nx<=0 || ny<=0 || nx>n || ny>n){
            // 격자 벗어나는 경우
            // 방향을 반대로 바꿈
            switch(cur_d){ // 상(0)->하(1), 좌(2)->우(3) 우(3)->좌(2)
                case 0:
                    cur_d=1;
                break;
                case 1:
                    cur_d=0;
                break;
                case 2:
                    cur_d=3;
                break;
                case 3:
                    cur_d=2;
                break;
            }
            
        }
        // 현재 격자 위치 업데이트
        cur_x+=dx[cur_d];
        cur_y+=dy[cur_d];
        // 주사위 업데이트 
        switch(cur_d){
            case 0: // 위로 굴러감
            {
                int temp=cube[0];
                cube[0]=cube[3]; //위->하값
                cube[3]=cube[1];//하->바닥값
                cube[1]=cube[2];//바닥->상값
                cube[2]=temp; //상->위값
            }
            break;
            case 1:  // 아래로 굴러감
            {
                int temp=cube[0];
                cube[0]=cube[2]; // 위->상값
                cube[2]=cube[1]; // 상->바닥값
                cube[1]=cube[3]; // 바닥->하값
                cube[3]=temp; // 하->위값  
            }
            break;
            case 2: // 왼쪽으로 굴러감
            {
                int temp=cube[0]; 
                cube[0]=cube[5]; // 위->우값
                cube[5]=cube[1]; // 우->바닥값
                cube[1]=cube[4]; // 바닥->좌값
                cube[4]=temp; // 좌->위값
            }
            break;
            case 3: // 오른쪽으로 굴러감
            {
                int temp=cube[0]; 
                cube[0]=cube[4]; // 위->좌값 
                cube[4]=cube[1]; // 좌->바닥값
                cube[1]=cube[5]; // 바닥->우값
                cube[5]=temp; // 우->위값  
            }
            break;
        }
    }
    int cal_score(){
        // 매 턴마다 상하좌우 인접하며 현재 칸과 같은 숫자 적힌 모든 칸 합만큼 점수 추가
        queue< pair<int,int> > q;
        bool visit[MAX_N+1][MAX_N+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++) visit[i][j]=false;
        }
        q.push(make_pair(cur_x,cur_y));
        visit[cur_x][cur_y]=true;
        int count=1;
        while(!q.empty()){
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx=cx+dx[i];
                int ny=cy+dy[i];
                if(nx<0 || ny<0 || nx>n || ny>n || visit[nx][ny]==true || matrix[nx][ny]!=matrix[cur_x][cur_y]) continue;
                visit[nx][ny]=true;
                q.push(make_pair(nx,ny));
                count++;
            }
        }
        return count*matrix[cur_x][cur_y];
    }
    void change_dir(){
        if(matrix[cur_x][cur_y]<cube[1]){
            // 90도 시계방향 회전 상(0)->우(3), 하(1)->좌(2), 좌(2)->상(0) 우(3)->하(1)
            switch(cur_d){
                case 0:
                    cur_d=3;
                break;
                case 1:
                    cur_d=2;
                break;
                case 2:
                    cur_d=0;
                break;
                case 3:
                    cur_d=1;
                break;
            }
        }
        else if(matrix[cur_x][cur_y]>cube[1]){
            switch(cur_d){ // 상(0)->좌(2), 하(1)->우(3),좌(2)->하(1),우(3)->상(0)
                case 0:
                    cur_d=2;
                break;
                case 1:
                    cur_d=3;
                break;
                case 2:
                    cur_d=1;
                break;
                case 3:
                    cur_d=0;
                break;
            }
        } // 동일하면 현재방향 유지
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Sols* sol=new Sols();

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> sol->matrix[i][j];
    }

    for(int i=0; i<m; i++){
        sol->move();
        sol->score+=sol->cal_score();
        //방향 전환
        sol->change_dir();
        sol->print();
    }
    cout << sol->score << "\n";
    return 0;
}