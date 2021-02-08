#include <stdio.h>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;
int BFS(int target1, int target2, deque<int> *graph, bool *visited, deque<int> *child){
    queue<int> q;
    visited[target1] = true; // check visited
    printf("[+] %d VISITED\n", target1);
    q.push(target1);
    (*child)[target1] = 0;
    while(!q.empty()){
        int current = q.front(); // get front element from queue
        
        q.pop(); // pop front element
        for(int num: graph[current]){
            if(visited[num] == false){
                q.push(num);
                visited[num] = true;
                (*child)[num] = (*child)[current] + 1; printf("%d: %d\n", num, (*child)[num]);
                
                printf("[+] %d VISITED\n", num);
                if(num == target2) return (*child)[num];
            }
        }
    }
    return -1; //queue가 empty가 되어도 num == target2인 조건이 없어서 리턴하지 못함 == target2 찾지 못함 == target2가 연결되어 있지 않음
}

int main(){
    int n, m, target1, target2; // n: # of nodes, m: # of edges

    scanf("%d", &n);
    scanf("%d %d", &target1, &target2);
    scanf("%d", &m);

    deque<int> graph[n];
    deque<int> child[n]; // parent - child
    bool visited[n]; // check if visited
    
    fill(visited, visited+n, false);
    
    for(int i=0; i<m; i++)
    {
        int u,v, result; 
        
        scanf("%d %d", &u, &v);
 
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    
    int result = BFS(target1-1, target2-1, graph, visited, child);

    printf("%d\n", result);
}