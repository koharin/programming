#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define MAX_N 1000
#define INF INT_MAX
using namespace std;

int N,M;
vector< pair<int,int> > V[MAX_N+1];

long long solution(int start,int end){
    priority_queue< pair<int,int> > pq;
    // create vector for distance
    vector<long long> dist(N+1, INF);
    //vector<bool> visited(N+1, 0);

    // insert source in priority_queue
    pq.push({0,start});
    // initialize distance as 0
    dist[start]=0;
    //visited[start]=true;

    while(!pq.empty()){
        int current=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        //visited[current]=true;
        if(dist[current]<cost) continue;

        for(auto next : V[current]){
            int nv=next.first;
            int weight=next.second;
            // 더 짧으면
            //if(visited[nv]==true) continue;
            if(dist[nv]>dist[current] + weight){
                dist[nv]=dist[current] + weight;
                pq.push({-dist[nv],nv}); // -로 넣어서 더 작은게 우선시되도록함
                //visited[nv]=true;
            }
            
        }
    }
    for(int n : dist) cout << n << " ";
    cout << "\n";
    return dist[end];
   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A,B;
    cin >> N;
    cin >> M;

    // create adjacency list
    for(int i=0; i<M; i++){
        int start,end,weight;
        cin >> start >> end >> weight;
        V[start].push_back({end,weight});
        //V[end].push_back({start,weight});
    }
    cin >> A >> B;

    cout << solution(A,B) << "\n";
    

    return 0;
}