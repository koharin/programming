#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#define MAX_NUM 8
#define WALL 3

using namespace std;

int N,M;
int map[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM];
int dx[]={-1,1,0,0,};
int dy[]={0,0,-1,1,};
vector< pair<int,int> > empty_v;
vector<int> selected_index;
vector< pair<int,int> > virus;
int ans=INT_MIN;

void Initialize(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) visited[i][j]=0;
    }
    for(int i=0; i<selected_index.size(); i++){
        pair<int,int> p=empty_v[selected_index[i]];
        map[p.first][p.second]=1;
    }    
}
int bfs(){
    queue< pair<int,int> > q;

    for(int i=0; i<virus.size(); i++){
        q.push(make_pair(virus[i].first, virus[i].second));
        visited[virus[i].first][virus[i].second]=1;
    }
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            // 이미 바이러스들은 visit 1이므로 map=2인지 체크 안해도 됨
            if(nx<0 || ny<0 || nx>=N || ny>=M || visited[nx][ny]==1 || map[nx][ny]==1) continue;
            // 빈 칸 방문 표시
            visited[nx][ny]=1;
            q.push(make_pair(nx,ny));
        }
    }
    int safe=0;
    // 종료 후 0인데 visited=0인건 안전 영역
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==0 && visited[i][j]==0) safe++;
        }
    }
    return safe;
}

void select(int index, int count){
    if(count==WALL){
        // 표시
        Initialize();
        ans=max(ans,bfs());
        // 표시 해제
        for(int i=0; i<selected_index.size(); i++){
            pair<int,int> p=empty_v[selected_index[i]];
            map[p.first][p.second]=0;
        }         
        return;
    }
    if(index==empty_v.size()) return;
    selected_index.push_back(index);
    select(index+1, count+1);
    selected_index.pop_back();
    select(index+1, count);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j]==0) empty_v.push_back(make_pair(i,j));
            if(map[i][j]==2) virus.push_back(make_pair(i,j));
        }
    }
    select(0,0);
    if(ans==INT_MIN) cout << 0 << "\n";
    else cout << ans << "\n";
    return 0;
}