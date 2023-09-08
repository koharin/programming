#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 1000000
using namespace std;

int N;
vector<int> graph[101];
int result[101];
int min_path=INF;

bool BFS(int start){
    int check[101]={0,}; // check if visited
    queue<int> q;
    q.push(start);
    check[start] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(int i=1; i <=N; i++){
            if(check[i] == false && graph[front][i]){ // front와 i가 인접한 경우
                q.push(i);
                check[i] = true;
                result[i] = result[front]+1; // 현재 친구에서 단계 수 = (처음 친구와 인접한 친구 관계) + (인접 친구와 현재 친구 관계 == 1)
            }
        }
    }

    // 각 정점에서 최단경로 구하고, 최소이면 min_path 업데이트
    int sum=0;
    for(int i=1; i<=N; i++) sum += result[i];
    if(sum < min_path) {
        min_path = sum;
        return true;
    }else return false;

}

int main(){
    int M; // N: 유저 수 (== 정점의 수)(2 <= N <= 100), M: 친구 관계 수(== 간선의 수) (1 <= M <= 5000)
    int answer=0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<M; i++){
        int A, B; // A, B: 두 친구

        cin >> A >> B;

        graph[A][B] = 1;
        graph[B][A] = 1;

    }

    for(int i=1; i<=N; i++){
        if(BFS(i)) answer = i;
        memset(result, 0, sizeof(result));
        memset(check, 0, sizeof(check));
    }

    //sort(r.begin(), r.end());
    //cout << r[0].second << endl;
    cout << answer << endl;

    return 0;
}