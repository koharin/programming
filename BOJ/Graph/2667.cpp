#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int cnt;
int graph[25][25];
bool visited[25][25];
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, 1, 0, -1};
void DFS(int x, int y, int N){
    cnt++;
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >=N || ny >= N) continue;
        if(graph[nx][ny] == 1 && !visited[nx][ny]) DFS(nx, ny, N);
    }
}

int main(){ 
    int N;
    scanf("%d", &N);
    deque<int> result;

    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<N; j++) graph[i][j] = s[j]-'0';
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j] == 1 && !visited[i][j]) { 
                cnt = 0;
                DFS(i, j, N); 
                result.push_back(cnt);
            }
        }
    }
    sort(result.begin(), result.end());
    printf("%d\n", result.size());
    for(int n: result) printf("%d\n", n);
}