#include <iostream>
#include <queue>
using namespace std;


int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int M,N;
int graph[50][50]={0,};

void search(int x, int y,int check){
    queue< pair<int,int> > q;
    q.push(make_pair(x,y));
    graph[x][y]=0;
    //cout << "visit x: " << x << ", y: " << y << endl;
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(graph[nx][ny]==check){
                graph[nx][ny]=0;
                q.push(make_pair(nx,ny));
                //cout << "visit x: " << nx << ", y: " << ny << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    
    for(int i=1; i<=T; i++){
        int answer=0;
        
        int K; cin >> M >> N >> K; // N: 세로, M: 가로
        for(int j=0; j<K; j++){
            int x,y; cin >> x >> y;
            graph[y][x]=i;
        }
        for(int m=0; m<N; m++){
            for(int n=0; n<M; n++){
                if(graph[m][n]!=i) graph[m][n]=0;
            }
        }
        
        for(int m=0; m<N; m++){
            for(int n=0; n<M; n++){
                if(!graph[m][n]) continue;
                search(m,n,i);
                // 한 번 돌고 돌아오면 개수++
                answer++;
                //cout << "current answer: " << answer << endl;
            }
        }
        cout << answer << endl;
    }
    return 0;
}