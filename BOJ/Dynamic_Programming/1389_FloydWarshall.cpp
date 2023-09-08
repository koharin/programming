#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#define INF 1000
using namespace std;

int graph[101][101];

void FloydWarshall(int N){

    // k = middle node
    for(int k=1; k<=N; k++){
        // i = source node
        for(int i=1; i<=N; i++){
            // j = destination node
            for(int j=1; j<=N; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main(){
    int N, M; // N: 유저 수 (== 정점의 수)(2 <= N <= 100), M: 친구 관계 수(== 간선의 수) (1 <= M <= 5000)
    int answer = INF;
    
    vector< pair<int,int> > result;

    //scanf("%d %d", &N, &M);
    cin >> N >> M;
    graph[0][0] = 0;
    for(int i=0; i<M; i++){ 
        int A, B; // A, B: 두 친구

        cin >> A >> B;
        //scanf("%d %d", &A, &B);
        graph[A][B] = 1;
        graph[B][A] = 1;
    }

    // i에서 한 번에 도달할 수 없는 경우 INF로 초기화
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == j) graph[i][j] = 0; // 정점 i와 정점 j가 동일한 경우는 0
            if(j != i && graph[i][j] != 1) graph[i][j] = INF; // 인접하지 않은 경우
        }
    }

    FloydWarshall(N);

    for(int i=1; i<=N; i++){
        int sum=0;
        for(int j=1; j<=N; j++){
            sum += graph[i][j];
        }
        if(sum < answer) { 
            answer = sum;
            result.push_back(make_pair(sum, i));
        }
    }

    sort(result.begin(), result.end());
    cout << result[0].second << endl;
    
    return 0;
}