#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V,E;

class Tree{
public:
    vector< pair< int, pair<int,int> > > edges;
    vector<int> parent;
    int weights;

    Tree(){
        weights=0;
        parent.resize(V+1);
        for(int i=1; i<=V; i++) parent[i]=i; // V 범위가 1부터임
    }
    
    int find_parent(int node){
        return (parent[node]==node) ? node : (parent[node]=find_parent(parent[node]));
    }
    void make_union(int p1, int p2){
        p1=find_parent(p1);
        p2=find_parent(p2);
        if(p1>p2) parent[p1]=p2;
        else if(p1<p2) parent[p2]=p1;
    }
    void Kruskal(){
        int count=0;
        for(int i=0; i<edges.size(); i++){
            int node1=edges[i].second.first;
            int node2=edges[i].second.second;
            // 사이클 형성하지 않으면
            if(find_parent(node1)!=find_parent(node2)){
                make_union(node1,node2);
                //cout << "(" << node1 << "," << node2 << "): " << edges[i].first << "\n";
                weights+=edges[i].first;
                //if(++count==V-1) break;
            }
        }
        cout << weights << "\n";
    }
};
int comparator(pair< int, pair<int,int> > a, pair< int, pair<int,int> > b)
{
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> V >> E;
    Tree* tree = new Tree();
    for(int i=0; i<E; i++){
        int A,B, C;
        cin >> A >> B >> C;
        tree->edges.push_back(make_pair(C, make_pair(A,B)));
    }
    // 가중치 오름차순 정렬
    sort(tree->edges.begin(), tree->edges.end(), comparator);

    tree->Kruskal();

    return 0;
}