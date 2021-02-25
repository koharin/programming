#include <stdio.h>
#include <deque>
#include <queue>
using namespace std;

void BFS(int start, deque<int> *graph, int *visited, int *count){
    queue<int> q;
    visited[start] = true;
    q.push(start);
    printf("[+] %d visited\n", start);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int next: graph[current]){
            if(visited[next] == false){
                visited[next] = true;
                q.push(next);
                printf("[+] %d visited\n", next);
            }
            else if(visited[next] == true && next == start){
                (*count)++; // 이미 방문했고, 인접한 정점이 처음 방문한 정점이면 사이클이므로 카운팅
                printf("[+] %d visited count: %d\n", next, *count);
                return;
            }
        }
    }
    

}

int main(){
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int N, count=0;
        scanf("%d", &N);
        deque<int> graph[N+1];
        int visited[N+1];
        fill(visited, visited+N+1, false);

        for(int j=1; j<=N; j++){
            int num; scanf("%d", &num);
            graph[j].push_back(num);
        }
        for(int j=1; j<=N; j++){
            printf("graph[%d]: ", j);
            for(int n: graph[j]) printf("%d ", n);
            printf("\n");
        }
        for(int j=1; j<=N; j++){
            if(visited[j] == false) BFS(j, graph, visited, &count);
        }
        printf("%d\n", count);
    }
}