#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
    int N,M;
    //vector<int> graph[N];
    int graph[101][101]={0,};
    int path[101][101]={0,};
    int visited[101][101]={0,};
    queue< pair<int, int> > q;
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        string s;
        cin >> s;

        for(int j=0; j<M; j++){
            int n = s[j] - '0';
            //graph[i].push_back(n);
            graph[i][j] = s[j]-'0';
        }
    }

    visited[0][0] = 1;
    path[0][0] = 1;
    q.push(make_pair(0,0));

    //cout << "path[0][0]: " << path[0][0] << endl;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(graph[nx][ny] == 1 && visited[nx][ny] == 0){
                visited[nx][ny] = 1;
                path[nx][ny] = path[cx][cy] + 1;
                q.push(make_pair(nx,ny));
                //cout << "path[" << nx << "][" << ny << "]: " << path[nx][ny] << endl;
            }
        }

    }

    cout << path[N-1][M-1] << endl;
    
    return 0;
}