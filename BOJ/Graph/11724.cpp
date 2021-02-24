#include <stdio.h>
#include <deque>
#include <queue>
using namespace std;

int BFS(int start, deque<int> *graph, bool *visited, int *count){
    queue<int> q;
    visited[start] = true;
    printf("[+] %d visited\n", start);
    q.push(start);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int n: graph[current]){
            if(visited[n] == false){
                q.push(n);
                visited[n] = true;
                printf("[+] %d visited\n", n);
            }
        }
    }
    return ++(*count);
}

int main(){
    int N, M, count=0; //N: 정점의 개수, M: 간선의 개수
    scanf("%d %d", &N, &M);
    deque<int> graph[N+1];
    bool visited[N+1];
    fill(visited, visited+N+1, false);
    
    for(int i=0; i<M; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=N; i++){
        if(visited[i] == false) { 
            BFS(i, graph, visited, &count); 
        }
    }
    printf("%d\n", count);
}