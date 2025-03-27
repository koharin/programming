#include <iostream>
#include <queue>
#include <climits>
#define EMPTY make_pair(-1,-1)
#define MAX_N 15
#define MAX_M 30
using namespace std;

int n,m;
int t; // 현재 시간
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
pair<int,int> people[MAX_M];
pair<int,int> conv[MAX_M];

void Input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }
    for(int i=0; i<m; i++){
        int x,y; cin >> x >> y;
        people[i]=EMPTY; // 격자 밖으로 초기화
        conv[i]=make_pair(x-1,y-1);
    }
}
void bfs(pair<int,int> start){
    queue< pair<int,int> > q;
    // 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j]=0;
            step[i][j]=0;
        }
    }
    q.push(make_pair(start.first, start.second));
    visited[start.first][start.second]=1;
    step[start.first][start.second]=0;
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=n || visited[nx][ny]==1 || map[nx][ny]==2) continue;
            visited[nx][ny]=1;
            step[nx][ny]=step[cx][cy]+1;
            q.push(make_pair(nx,ny));
        }
    }
}
void step1(){
    for(int i=0; i<m; i++){
        if(people[i]==EMPTY || people[i]==conv[i]) continue;
        bfs(conv[i]);

        int min_dist=INT_MAX;
        int min_x=-1, min_y=-1;
        int cx=people[i].first;
        int cy=people[i].second;
        for(int i=0; i<4; i++) // 현재 위치 기준 상,좌,우,하 확인
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(visited[nx][ny] && map[nx][ny]!=2 && min_dist>step[nx][ny]){
               min_dist=step[nx][ny];
               min_x=nx;
               min_y=ny; 
            }
        }
        people[i]=make_pair(min_x,min_y);
    }
}
void step3(){
    // t번 사람이 가고싶은 편의점과 가장 가까운 베이스 캠프에 들어감
    bfs(conv[t-1]); // 1번은 배열 인덱스 0번이므로 
    
    int min_dist=INT_MAX;
    int min_x=-1, min_y=-1;
    for(int i=0; i<n; i++){ // 행이 작은게 우선
        for(int j=0; j<n; j++){ // 행이 같으면 열이 작은게 우선
            if(visited[i][j] && map[i][j]==1 && min_dist>step[i][j]){
                min_dist=step[i][j];
                min_x=i;
                min_y=j;
            }
        }
    }
    people[t-1]=make_pair(min_x,min_y);
    // 들어간 적 있는 베이스 캠프는 갈 수 없음
    map[min_x][min_y]=2;
}
void solution(){
    // Step 1. p!=EMPTY, p!=conv 이면 한 칸 전진
    step1();
    // Step 2. 편의점 도착 시 편의점 도달 불가능 표시
    for(int i=0; i<m; i++){
        if(people[i]==conv[i]){
            map[people[i].first][people[i].second]=2;
        }        
    }
    // Step 3. t<=m 만족 여부 확인
    if(t>m) return;
    step3();
}
bool End(){
    bool check=true;
    // 사람이 모두 편의점 도착했는지 확인
    for(int i=0; i<m; i++){
        if(people[i]!=conv[i]) { check=false; break; }
    }
    return check;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    Input();

    while(true){
        t++;
        solution();
        if(End()) break;
    }
    cout << t << "\n";

    return 0;
}