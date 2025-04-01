#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 2000
using namespace std;

struct EDGE{
    long long cost;
    int from,to;
};

int N;
long long C;
vector< pair<int,int> > nodes;
vector<int> parent(MAX_N,0);
vector<EDGE> edges;
long long answer;

void calc_cost(){
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            int x1=nodes[i].first, x2=nodes[j].first;
            int y1=nodes[i].second, y2=nodes[j].second;
            long long cost=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
            if(cost>=C){
                EDGE edge;
                edge.cost=cost;
                edge.from=i;
                edge.to=j;
                edges.push_back(edge);                
            }
        }
    }    
}

bool comparator(EDGE a, EDGE b){
    if(a.cost <= b.cost) return true;
    return false;
}

int find_parent(int node){
    return (parent[node]==node) ? node : (parent[node]=find_parent(parent[node]));
}

void unite(int p1, int p2){
    p1=find_parent(p1);
    p2=find_parent(p2);
    if(p1>p2) parent[p1]=p2;
    else if(p1<p2) parent[p2]=p1;        
    
}

long long Kruskal_MST(){
    int count=0;
    sort(edges.begin(), edges.end(), comparator);
    for(int i=0; i<edges.size(); i++){
        int from=edges[i].from;
        int to=edges[i].to;
        if(find_parent(from)!=find_parent(to)){
            unite(from,to);
            answer += edges[i].cost;
            if(++count == N-1) break;
        }
    }
    if(count==N-1) return answer;
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> C;
    parent.resize(N);
    for(int i=0; i<N; i++){
        int x,y; cin >> x >> y;
        nodes.push_back(make_pair(x,y));
        parent[i]=i;
    }
    calc_cost();
    cout << Kruskal_MST() << endl;
    return 0;
}