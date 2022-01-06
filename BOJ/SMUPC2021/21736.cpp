#include <iostream> 
#include <deque> 
using namespace std; 
int N, M; // N: 세로, M: 가로 
int visited[600][600]; 
int cnt=0;
int dx[] = {1, 0, -1, 0}; 
int dy[] = {0, 1, 0, -1}; 
void DFS(int x, int y, deque<char> *graph){ 
    if(graph[x][y] == 'P') cnt++;
    visited[x][y] = 1; 
    for(int i=0; i<4; i++){ 
        int nx = x + dx[i]; 
        int ny = y + dy[i]; 
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue; 
        if(!visited[nx][ny] && graph[nx][ny] != 'X' && graph[nx][ny] != 'I') DFS(nx, ny, graph); 
    } 
} 
int main(){ 
    scanf("%d %d", &N, &M); 
    deque<char> graph[N]; 
    for(int i=0; i<N; i++){ 
        string str; 
        cin >> str; 
        for(char c: str) graph[i].push_back(c); 
    } 
    for(int i=0; i<N; i++){ 
        for(int j=0; j<M; j++){  
            if(graph[i][j] == 'I'){ 
                DFS(i, j, graph); 
            } 
        } 
    } 
    if(cnt > 0)printf("%d", cnt); 
    else printf("TT");
}
