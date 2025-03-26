#include <iostream>
#include <queue>
#define MAX_NUM 50
#define SIDEWALK 1
#define ROAD 0
using namespace std;

int n,m,x,y,d;
// 0(북), 1(동), 2(남), 3(서)
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int road[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM];

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) cout << 2 << " ";
            else cout << road[i][j] << " ";
        }
        cout << endl;
    }
}

void Input(){
    cin >> n >> m;
    cin >> x >> y >> d;
    // 1: 인도, 0: 도로
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> road[i][j];
    }
}

bool check(int x, int y){
    return x>=1 && y>=1 && x<n-1 && y<m-1 && visited[x][y]==0 && road[x][y]==ROAD;
}

int direction(int d){
    switch(d){
        case 0:
        d=3;
        break;
        case 1:
        d=0;
        break;
        case 2:
        d=1;
        break;
        case 3:
        d=2;
        break;
    }
    return d;   
}

bool drive(){
    visited[x][y]=1;
    // (x,y) 기준 왼쪽방향의 상하좌우 봄
    for(int i=0; i<4; i++){
        d=direction(d);
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(!check(nx,ny)) continue;
        x=nx;
        y=ny;
        return true;
    }
    // 4개 다 봤는데 return되지 않았으면, x,y에서 d 유지하면서 후진
    if(road[x-dx[d]][y-dy[d]]==0){
        x=x-dx[d];
        y=y-dy[d];
        return true;
    }else{
        return false;
    }

}
int solution(){
    int cnt=0;
    for(int i=1; i<n-1; i++){
        for(int j=1; j<m-1; j++){
            if(visited[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Input();
    // 초기 상태 방문 면적 1로 가정
    //visited[x][y]=1;
    
    while(true){
        bool state=drive();
        if(!state) break;
    }
    int ans=0;
    // visited 개수 구하기
    cout << solution() << endl;
    return 0;
}