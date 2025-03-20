#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n,L,R;
int graph[50][50]={0,};
int visited[50][50]={0,};
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
vector< pair<int,int> > merging;

void search(int x, int y){
    queue< pair<int,int> > q;
    q.push(make_pair(x,y));
    visited[x][y]=1;
    merging.push_back(make_pair(x,y));
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        // 인접한 계란과 차이 확인
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=n || visited[nx][ny]==1) continue;
            int distance=abs(graph[cx][cy]-graph[nx][ny]);
            if(distance>=L && distance <= R){
                visited[nx][ny]=1;
                q.push(make_pair(nx,ny));
                merging.push_back(make_pair(nx,ny));
            }
        }
    }
}

void mergeEgg(){
    int sum=0;
    for(pair<int,int> p: merging){
        sum+=graph[p.first][p.second];
    }
    
    int distribute=sum/(merging.size()); // 소숫점 버림
    cout << "current sum: " << sum << ", distribute: " << distribute << "\n";
    for(pair<int,int> p: merging){
        graph[p.first][p.second]=distribute;
    }
}
bool moveEgg(){
    // 계란 이동 여부
    bool move=false;
    // visit 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) visited[i][j]=0;
    }
    // 전반적으로 탐색하면서 계란 합침
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // merge 목록 초기화
            
            if(visited[i][j]==0) { 
                search(i,j); 
                // 합쳐야 할 리스트
                for(pair<int,int> p: merging){
                    cout << p.first << ", " << p.second << " ";
                    
                }
                cout << "\n";
                // 계란 이동
                if(merging.size()>=2) {
                    mergeEgg(); 
                    move=true;
                }
                merging.clear();
            }
        }
    }   
    return move; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int ans=0;
    cin >> n >> L >> R;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> graph[i][j];
    }
    while(true){
        // 전체적으로 돌면서 계란 합침
        bool move = moveEgg();
        if(!move) break;
        ans++;
        cout << ans << endl;
    }
    cout << ans << "\n";
    
    return 0;
}