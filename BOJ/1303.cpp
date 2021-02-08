#include <stdio.h>
#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;
int N, M; // N: width, M: height
const int dx[] = {-1, 0, 1, 0}, dy[] = {-1, 0, 1, 0};
bool check[100][100];
int floodfill(int x, int y, deque<char> *graph, char soldier){
    int count=1;
    check[x][y] = true;
    for(int i=0; i<4; i++){
        int row = x + dx[i], col = y + dy[i];
        if(row >= N || col >= M || row < 0 || col < 0) continue;
        if(!check[row][col] && graph[row][col] == soldier) count += floodfill(row, col, graph, soldier);
    }
    return count;
}

int main(){

    scanf("%d %d", &N, &M);

    deque<char> graph[N];
    unordered_map<char, int> result; // result[0]: white soldier result[1]: black soldier

    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(char c: str){
            graph[i].push_back(c);
        }
    }
    result.insert({'W', 0});
    result.insert({'B', 0});
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!check[i][j])
            {
                int r = floodfill(i, j, graph, graph[i][j]);
                if(graph[i][j] == 'W') result['W'] += r*r;
                else result['B'] += r*r;
            }
        }
    }

    printf("%d %d", result['W'], result['B']);
}