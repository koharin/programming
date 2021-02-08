#include <iostream>
#include <stdio.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

void DFS(int start, deque<int> *graph, bool *check, deque<int> *DFS_result){
    stack<int> s;
    check[start] = true;
    s.push(start);
    (*DFS_result).push_back(start);
    printf("[+] %d VISITED\n", start);

    while(!s.empty()){
        int current = s.top(); 
        s.pop(); printf("[+] POPED %d\n", current);
        //(*DFS_result).push_back(current);
        for(int next: graph[current]){
            if(check[next] == false){
                s.push(current);
                s.push(next); 
                check[next] = true;
                (*DFS_result).push_back(next);
                printf("[+] %d VISITED\n", next);
                break;
            }
        }

    }
}
void BFS(int start, deque<int> *graph, bool *check, deque<int> *BFS_result){
    queue<int> q;
    check[start] = true;
    q.push(start);
    printf("[+] %d VISITED\n", start);
    
    while(!q.empty()){
        int front = q.front(); printf("[+] POPED %d\n", front);
        (*BFS_result).push_back(front);
        q.pop();
        for(int num: graph[front]){
            if(check[num] == false){
                q.push(num);
                check[num] = true;
                printf("[+] %d VISITED\n", num);
            }
        }
    }
}

int main(){
    int N, M, V; //N: 정점의 수, M: 간선의 수, V: 시작할 정점의 번호

    scanf("%d %d %d", &N, &M, &V); 

    deque<int> graph[N];
    deque<int> DFS_result;
    deque<int> BFS_result;
    bool DFS_check[N];
    bool BFS_check[N];
    fill(DFS_check, DFS_check+N, false);
    fill(BFS_check, BFS_check+N, false);

    for(int i=0; i<M; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    for(int i=0; i<N; i++) sort(graph[i].begin(), graph[i].end());

    DFS(V-1, graph, DFS_check, &DFS_result);
    BFS(V-1, graph, BFS_check, &BFS_result);

    printf("RESULT OF DFS: ");
    for(int i: DFS_result) printf("%d ", i+1);

    printf("\nRESULT OF BFS: ");
    for(int i: BFS_result) printf("%d ", i+1);

}