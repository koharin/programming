#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 5000

using namespace std;
vector< pair<int,int> > graph[MAX_N+1];
int N,Q;

void search(int k, int v){
    vector<bool> visited(N+1, false);
    int answer=0;
    queue<int> q;
    q.push(v);
    visited[v]=true;

    while(!q.empty()){
        int current=q.front();
        q.pop();

        for(int i=0; i<graph[current].size(); i++){
            int next=graph[current][i].first;
            int cost=graph[current][i].second;
            if(visited[next]==false && cost>=k){
                visited[next]=true;
                q.push(next);
                answer++;
            }
        }
    }
    cout << answer << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    
    for(int i=0; i<N-1; i++){
        int p,q,r; 
        cin >> p >> q >> r;
        graph[p].push_back(make_pair(q,r));
        graph[q].push_back(make_pair(p,r));
    }
    for(int i=0; i<Q; i++){
        int k,v;
        cin >> k >> v;
        search(k,v);
    }

    return 0;
}