#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int start, vector<int> *graph, bool *visited){
    visited[start] = true;

    for(int next: graph[start]){
        if(!visited[next]) DFS(next, graph, visited);
    }
}

void BFS(int start, vector<int> *graph, bool *visited){
    queue<int> q;
    visited[start] = true;
    q.push(start);
    printf("%d visited.\n", start);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int next: graph[current]){
            if(visited[next] == false){
                visited[next] = true;
                q.push(next);
                printf("%d visited.\n", next);
            }
        }
    }

}
int solution(int n, vector<vector<int>> computers){
    vector<int> graph[n];
    bool visited[n];
    int cnt=0;
    fill(visited, visited+n, false);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(computers[i][j] == 1){
                graph[i].push_back(j);
            }
        }
    }
    
    
    for(int i=0; i<n; i++){
        if(visited[i] == false) { 
            //BFS(i, graph, visited); 
            DFS(i, graph, visited);
            cnt++; printf("%d\n", cnt);
        }
    }
    
    return cnt;
}

int main(){
    int n; // n: # of computers
    scanf("%d", &n);
    vector<vector<int>> computers;

    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<n; j++){
            int num; scanf("%d", &num);
            v.push_back(num);
        }
        computers.push_back(v);
    }

    printf("%d\n", solution(n, computers));
}