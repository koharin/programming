#include <iostream>

using namespace std;

struct NODE{
    int dest;
    int level;
};

vector<NODE> graph[10001];


int main(){
    int N, M;
    int answer=0;

    cin >> N >> M;

    for(int i=0; i<M; i++){
        int A,B,C;

        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});

    }


    return 0;
}