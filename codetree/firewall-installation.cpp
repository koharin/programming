#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
//동(0,1) 서(0,-1) 북(-1,0) 남(1,0)
int n,m;
int graph[8][8]={0,};
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int v_fire[8][8]={0,};
vector<int> selected;
vector< pair<int,int> > empty_place;
int ans=INT_MIN;

// 불 번지는거 구하기
void fire(int x, int y){
    queue< pair<int,int> > q;
    q.push(make_pair(x,y));
    v_fire[x][y]=1;
    
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||v_fire[nx][ny]==1||graph[nx][ny]==1) continue;
            v_fire[nx][ny]=1;
            //graph[nx][ny]=2; // fire로 바꾸기
            q.push(make_pair(nx,ny));
        }
        
    }
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]==0 && v_fire[i][j]==1) cout << 2;
            else cout << graph[i][j];
        }
        cout << endl;
    }    
    cout << endl;
    */
}

void search(){
    int count=0;
    // visited 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) v_fire[i][j]=0;
    }
    // selected에 넣은 위치에 방화벽 설치
    for(int i=0; i< (int)selected.size(); i++){
        graph[empty_place[selected[i]].first][empty_place[selected[i]].second]=1;
    }
    // 탐색
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]==2 && v_fire[i][j]==0) fire(i,j);
        }
    }
    // 빈 칸 개수 구하기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]==0 && v_fire[i][j]==0) count++;
        }
    }
    ans=max(ans,count);

    // 다음 탐색 위해 방화벽 제거
    for(int i=0; i< (int)selected.size(); i++){
        graph[empty_place[selected[i]].first][empty_place[selected[i]].second]=0;
    }
}

void select(int index, int count){ // index: empty_place에서 인덱스, count: 방화벽 개수
    // 방화벽 3개 다 설치한 경우
    if(count==3){
        // 불 번지는 영역 구하기
        search();
        return;
    }
    if(index == (int)empty_place.size()) return;
    selected.push_back(index);
    select(index+1, count+1);
    selected.pop_back();
    select(index+1, count); // 이전꺼 선택 안하고 다음꺼 선택했을 때도 구함
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) { 
            cin >> graph[i][j];
            // 빈 칸인 위치 다 넣기 
            if(graph[i][j]==0) empty_place.push_back(make_pair(i,j));
        }
    }
    // 방화벽 설치 조합 구하기
    select(0,0);

    cout << ans << endl;
    return 0;
}
// Backtracking으로 방화벽 설치할 수 있는 모든 조합 만들기
// 각 조합에서 BFS로 불 퍼지는 영역 구하고, 방문한 적 없는 빈 칸 개수를 세면 됨
