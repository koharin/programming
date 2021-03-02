#include <iostream>
#include <deque>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int visited[50][50];
int graph[50][50];

void DFS(int x, int y, int w, int h){
    visited[x][y] = 1;
    printf("graph[%d][%d] visited.\n", x, y);
    for(int i=0; i<8; i++){
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if(graph[nx][ny] == 1 && !visited[nx][ny]) DFS(nx, ny, w, h);
    }
}

int main(){
    while(true){
        int w, h;
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0) break;
        int cnt=0;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                int num; scanf("%d", &graph[i][j]);
                visited[i][j] = 0;
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(graph[i][j] == 1 && !visited[i][j]) { 
                    DFS(i, j, w, h); 
                    cnt++; 
                }
            }
        }
        printf("%d\n", cnt);
    }
}