// [21년 재직자 대회 본선] 거리 합 구하기
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct NODE{
    int dest;
    int cost;
};

vector<NODE> graph[200001];
int result[200001][200001];
int check[200001];
int subtree[200001];
int distance[200001];


void DFS(int current, int parent, int N){
    subtree[current] = 1; // 현재 노드(current)가 루트노드일 때 루트노드만 갖는 subtreesize = 1
    for(int i=1; i<=N; i++){
        int child = graph[i].first;
        int cost = graph[i].second;
        if(child != parent) { 
            DFS(current, parent, N);
            subtree[current] += subtree[child]; // current 노드에 child 노드를 합함
            distance[current] += distance[child] + cost * subtree[child]; // current 노드 총 가중치 = child 노드 가중치 + (child 노드 총 자식노드개수*가중치)
        }
    }
}

void BFS(int start, int N){
    queue<int> q;
    check[start] = 1;
    q.push(start);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i=1; i<=N; i++){
            if(!check[i]){
                q.push(i);
                check[i] = 1;
                result[start][i] = result[start][front] + graph[front][i];
                result[i][start] = result[front][start] + graph[front][i];
            }
        }
    }
}

int main(){
    int N;

    cin >> N;

    // input (construct graph)
    for(int i=0; i<N; i++){
        int x,y,t;
        cin >> x >> y >> t;
        
        graph[x].push_back({y,t});
        graph[y].push_back({x,t});
    }
   
    for(int i=0; i<N; i++){
        for(auto node: graph[i]){
            cout << node.dest << " " << node.cost << endl;
        }
    }

    return 0;
}