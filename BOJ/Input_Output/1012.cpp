#include <stdio.h>
#include <deque>

using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {-1, 1, 0, 0};

void floodfill(int **cabbage, bool **visited, deque<int> *result){

}

int main(){
    int T; // T: # of testcases
    deque<int> result;

    scanf("%d", &T);
    
    for(int i=0; i<T; i++){
        int M, N, K; // M: width, N: height, K: # of Cabbage
        scanf("%d %d", &M, &N, &K);
        int cabbage[M][N] = {{0,}};
        bool visited[M][N] = { {false} };

        for(int i=0; i<K; i++){
            int x,y;
            scanf("%d %d", &x, &y);
            cabbage[x][y] = 1;
        }
        floodfill(cabbage, visited, &result);
    }


}