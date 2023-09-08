#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){

    int N,M;
    
    scanf("%d %d", &N, &M);
    vector<pair<int, int>> r_ls(N+1, make_pair(0,0)); // range length, speed
    vector<pair<int, int>> t_ls(M+1, make_pair(0,0)); // test length, speed
    vector<int> result(M,0); 
    int max=100;
    
    for(int i=0; i<N; i++)
        scanf("%d %d", &r_ls[i].first, &r_ls[i].second);
    for(int i=0; i<M; i++)
        scanf("%d %d", &t_ls[i].first, &t_ls[i].second);

    for(int i=1; i<=M; i++){ // i: 연정이 구간
        int c_length=t_ls[i].first;
        int c_speed=t_ls[i].second;
        result[i]= max((int)(c_speed > r_ls[]))
    }
    
    return 0;
}