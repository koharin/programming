#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 동,서,남,북
int dx[]={0,0,0,1,-1};
int dy[]={0,1,-1,0,0};
int dice[6]={1,6,3,4,5,2}; // 위, 아래, 동(0,1),서(0,-1),남(1,0),북(-1,0)
int N,M,K;
int dir;

int cal_C(int x, int y, int B, vector< vector<int> > &v){
    int count=1;
    queue< pair<int,int> > q;
    int visited[20][20]={0,}; // 초기화 필수(안 그럼 visit 제대로 계산 안됨)
    q.push(make_pair(x,y));
    visited[x][y]=1;
    
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=1; i<=4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            //cout << "current " << nx << "," << ny << ": " << v[nx][ny] << "count: " << count << endl;
            if(v[nx][ny]==B && visited[nx][ny]==0){
                visited[nx][ny]=1;
                q.push(make_pair(nx,ny));
                count++;
                //cout << "current " << nx << "," << ny << ": " << v[nx][ny] << "count: " << count << endl;
            }
        }        
    }
    return count;
}

void moveValid(int dir){
    int temp=dice[0];
    switch(dir){
        case 1: // 동으로 이동
            dice[0]=dice[3];//위->서값
            dice[3]=dice[1];//서->바닥값
            dice[1]=dice[2];//바닥->동값
            dice[2]=temp;//동->위값
            // 남,북 변화 없음
        break;        
        case 2: // 서로 이동
            dice[0]=dice[2]; // 위->동값
            dice[2]=dice[1];// 동->바닥값
            dice[1]=dice[3];// 바닥->서값
            dice[3]=temp;// 서->위값
            // 남,북 변화 없음
        break;
        case 3: // 북->남으로 이동
            
            dice[0]=dice[5]; //위->북값
            dice[5]=dice[1];//북->바닥
            dice[1]=dice[4];//바닥->남
            dice[4]=temp;//남->위
            //동,서 변화 없음
        break;
        case 4: // 남->북으로 한 칸 이동
            
            dice[0]=dice[4]; // 위->남값
            dice[4]=dice[1];//남->바닥값
            dice[1]=dice[5];//바닥->북값
            dice[5]=temp;//북->위값
            //동,서 변화 없음
        break;        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    vector< vector<int> > v(N, vector<int>(M,0));
    
    int x=0,y=0; // 항상 (1,1)에서 시작
    int score=0;
    dir=1; // 가장 처음 주사위 이동 방향은 동쪽(1)
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> v[i][j];
    }
    for(int i=0; i<K; i++){
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        int C; // 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수  

        // 이동방향에 칸이 없는 경우
        if(nx<0 || ny<0 || nx>=N || ny>=M){
            // 이동 방향 반대로 한 칸 굴러감
            switch(dir){
                case 1:
                    dir=2;
                break;
                case 2:
                    dir=1;
                break;
                case 3:
                    dir=4;
                break;
                case 4:
                    dir=3;
                break;
            }
            nx=x+dx[dir];
            ny=y+dy[dir]; 

        } 
        // 이동 방향으로 한 칸 굴러감   
        moveValid(dir);

        // A: 주사위 아랫면에 있는 정수
        int A=dice[1];
        // B:(x,y)에 있는 정수
        int B=v[nx][ny];  

        // 주사위가(dice[1]) 도착한 칸(x,y)에 대한 점수 획득
        C=cal_C(nx,ny,B,v);
        score+=B*C;

        // 좌표 업데이트
        x=nx; y=ny;

        // 이동 방향 업데이트
        // 90도 시계 방향 회전
        if(A>B){
            switch(dir){
                case 1:
                dir=3; break;
                case 2:
                dir=4; break;
                case 3:
                dir=2; break;
                case 4:
                dir=1; break;
            }
        }else if(A<B){
            switch(dir){
                case 1:
                dir=4; break;
                case 2:
                dir=3; break;
                case 3:
                dir=1; break;
                case 4:
                dir=2; break;
            }            
        }
        // A=B인 경우 dir 유지
        //cout << "current dir: " << dir << "pos: " << nx << ", " << ny << "A: " << A << ", B: " << B << "C: " << C << " score:" << score << endl;
    }
    cout << score << endl;
}