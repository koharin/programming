#include <stdio.h>
#include <algorithm>
using namespace std;

void DFS(int start, int *graph, bool *visited, bool *done, int *count){
    visited[start] = true;
    printf("[+] %d visited\n", start);
    int next = graph[start];
    if(visited[next] == false){
        DFS(next, graph, visited, done, count);
    }
    // count that included in project
    else if(!done[next]){
        for(int i=next; i !=start; i=graph[i]) { (*count)++; printf("%d counted.\n", i); } 
        (*count)++; // for counting start
        printf("%d counted.\n", start);
    }
    done[start] = true;
}

int main(){
    int T; // T: # of testcase
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int n;
        int count=0; // n: # of students
        scanf("%d", &n);
        int graph[n+1]={0,};
        bool visited[n+1];
        bool done[n+1];
        fill(visited, visited+n+1, false);
        fill(done, done+n+1, false);

        for(int j=1; j<=n; j++) scanf("%d", &graph[j]);
        
        for(int j=1; j<=n; j++){
            if(visited[j] == false) DFS(j, graph, visited, done, &count);
        }
        
        printf("%d\n", n-count);
    }
}