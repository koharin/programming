#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#define MAX_N 50
#define MAX_M 10
using namespace std;

int N,M;
int graph[MAX_N][MAX_N];
int visited[MAX_N][MAX_N]={0,}; // 방문 처리
vector< pair<int,int> > hospital;
vector< pair<int,int> > virus;
vector<int> select_idx; // 선택된 hospital index
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool virus_remain;
int ans=INT_MAX;

// 매 초 상하좌우 인접 지역에 백신 공급해서 바이러스 사라짐
int kill(){
    int time[MAX_N][MAX_N]={0,}; // 시간 저장
    int max_time=0; // 바이러스 원래 하나도 없는 경우엔 그냥 0으로 반환하도록
    queue< pair<int,int> > q;

    // 병원들 queue에 넣기
    for(int i=0; i<select_idx.size(); i++){
        pair<int,int> p=hospital[select_idx[i]];
        q.push(p);
        time[p.first][p.second]=0; // 각 병원을 시작 시간을 0으로 표시
        visited[p.first][p.second]=1;
    }
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        int current_time=time[cx][cy];
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=N || graph[nx][ny]==1 || visited[nx][ny]==1) continue; 
            time[nx][ny]=current_time+1;
            visited[nx][ny]=1;
            q.push(make_pair(nx,ny));
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            if(graph[i][j]==0) {
                // 바이러스 하나라도 남아있으면 INT_MAX 반환
                if(visited[i][j]==0) return INT_MAX;
                else max_time=max(max_time, time[i][j]);
            }
            
        }
    }
    
    //cout << max_time << endl;
    return max_time;
}

void select(int index, int count){
    if(count==M){ // 0부터 시작이므로 M개이면
        // 정렬
        sort(select_idx.begin(), select_idx.end());
        int kill_time;
        // visit 초기화
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) visited[i][j]=0;
        // virus 상태 초기화
        virus_remain=false;
        // 선택된 병원
        //cout << "selected hospital: ";
        //for(int idx: select_idx) cout << idx << " ";
        //cout << endl;
        // M개 선택했을 때 바이러스 없애기
        ans=min(ans, kill());

        return;
    }
    if(index==hospital.size()) return;
    select_idx.push_back(index);
    // index 다음으로 선택함
    select(index+1, count+1); 
    // index 선택 안했을 때에도 구함
    select_idx.pop_back();
    select(index+1, count);
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];
            if(graph[i][j]==0) virus.push_back(make_pair(i,j));
            if(graph[i][j]==2) hospital.push_back(make_pair(i,j));
        }
    }
    sort(hospital.begin(), hospital.end());
    select(0,0); // hospital 첫번째부터 M개 골라서 시간 구하기
    if(ans==INT_MAX) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}

// 전체 병원 중 M개 병원 고르기 -> backtracking