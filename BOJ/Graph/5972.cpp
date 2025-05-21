// shortest distance -> dijkstra's algorithm
// 각 node u, neighbor v에 대해 dist[v]=dist[u]+weight[u][v]로 업데이트 new path가 기존에 알던 path보다 shorter distance인 경우에만 업데이트
#include <iostream>
#include <climits>
#include <queue>
#define INF INT_MAX
#define MAX_N 50000
using namespace std;

int N,M;
vector< pair<int,int> > V[MAX_N+1];
int solution(int start){
        int answer=0;
        // create priority queue 
        priority_queue< pair<int,int> > pq;
        // create vector for distance and initialize all distance as INF
        vector<int> dist(N+1,INF);

        // insert source in priority queue and
        // initialize its distance as 0
        pq.push({0,start});
        dist[start]=0;

        // looping till priority queue becomes empty
        while(!pq.empty()){
            // first vertex in pair is the minimum distance vertex,
            // so extract it from pq
            int u = pq.top().second;
            pq.pop();

            // get all adjacent of u
            for(auto x : V[u]){
                int weight=x.second;
                int v=x.first;

                // if shorter path 
                if(dist[v] > dist[u] + weight){
                    // update distance of v
                    dist[v] = dist[u] + weight;
                    pq.push({-dist[v],v});
                }
            }
        }
        answer=dist[N];
        return answer;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<M; i++){
        int A,B,C;
        cin >> A >> B >> C;
        V[A].push_back(make_pair(B,C));
        V[B].push_back(make_pair(A,C));
    }

    cout << solution(1) << "\n";

    return 0;
}