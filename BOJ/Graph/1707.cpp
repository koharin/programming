#include <stdio.h>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

void DFS(int start, deque<int> *graph, int *color, bool *CheckBipartite){
    stack<int> s;
    color[start] = start;
    s.push(start);

    while(!s.empty()){
        int current = s.top();
        s.pop();
        for(int next: graph[current]){
            if(color[next] == 0){
                s.push(current);
                s.push(next);
                color[next] = color[current]*-1;
            }
            else if(color[next] + color[current] != 0){
                *CheckBipartite = false;
                return;
            }
        }
    }
}

void BFS(int start, deque<int> *graph, int *color, bool *CheckBipartite){
    queue<int> q;
    color[start] = start; // +start
    q.push(start);
    printf("[+] %d visited. color[%d] = %d\n", start, start, color[start]);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int num: graph[current]){
            if(color[num] == 0){ // if not visited
                q.push(num);
                color[num] = color[current]*-1; // -start 
                printf("[+] %d visited. color[%d] = %d\n", num, num, color[num]);
            }
            else if(color[num] + color[current] != 0) {
                *CheckBipartite = false;
                return; 
            }
        }
    }
}

int main(){
    int K; // K: 테스트 케이스의 개수
    scanf("%d", &K);

    for(int i=0; i<K; i++){
        int V, E; // V: 정점의 개수, E: 간선의 개수
        scanf("%d %d", &V, &E);
        
        deque<int> graph[V+1];
        int color[V+1]; // check not visitied by 0
        bool CheckBipartite = true;
        fill(color, color+V+1, 0); // initialize

        for(int j=0; j<E; j++){
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int j=1; j<=V; j++){
            if(CheckBipartite == false) break;
            //if(color[j] == 0) BFS(j, graph, color, &CheckBipartite);
            if(color[j] == 0) DFS(j, graph, color, &CheckBipartite);
        }
        printf("%s\n", CheckBipartite == true ? "YES" : "NO");
    }
}