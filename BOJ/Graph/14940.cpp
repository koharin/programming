#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int graph[1000][1000];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int visited[1000][1000];
int answer[1000][1000];
int n,m;

void search(int x, int y,int num){
    queue< pair<int,int> > q;
    q.push(make_pair(x,y));
    visited[x][y]=1;
    answer[x][y]=num;
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            // 0이면 방문하지 못함
            if(nx<0 || ny<0 || nx>n || ny>m || graph[nx][ny]==0) continue;
            if(!visited[nx][ny]){
                visited[nx][ny]=1;
                
                answer[nx][ny]=answer[cx][cy]+1;
                //cout << "answer " << nx << ", " << ny << ": " << answer[nx][ny] << endl;
                q.push(make_pair(nx,ny));
            }
        }        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tx,ty;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
            if(graph[i][j]==2){
                tx=i; ty=j;
            }
        }
    }
    int num=0;
   /*
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) continue;
            num=sqrt(pow(i-tx,2)+pow(j-ty,2));
            //cout << num << endl;
            search(i,j,tx,ty,num);
        }
    }
    */
    search(tx,ty,0);

    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) {
                cout << answer[i][j] << " ";
            }
            else {
                if(graph[i][j]==0) cout << 0 << " ";
                else cout << -1 << " ";
            }
        }
        cout << endl;
    }    
    

    return 0;
}