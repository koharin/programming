#include<iostream>
#include<vector>

using namespace std;


int main(int argc, char** argv)
{
    int n,m, S,T;
    
    cin >> n >> m;

    vector<int> graph[n+1];
    
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    cin >> S >> T;

    
    return 0;
}