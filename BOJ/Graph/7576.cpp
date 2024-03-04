#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int M,N;
int nx[] = {1,0,-1,0};
int ny[] = {0,1,0,-1};
//int tomato[1000][1000]={0,};

void search(queue< pair<int,int> > &q, vector< vector<int> > &tomato){

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        //cout << "visit (" << cx << "," << cy << "):" << tomato[cx][cy] << endl;
        q.pop();
        for(int i=0; i<4; i++){
            int next_x = cx + nx[i];
            int next_y = cy + ny[i];
            if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
            if(tomato[next_x][next_y] == 0){
                // (cx,cy)와 인접한 토마트는 (cx,cy)익은 날짜+1에 익게 됨
                tomato[next_x][next_y] = tomato[cx][cy]+1;
                //cout << "visit (" << next_x << "," << next_y << "):" << tomato[next_x][next_y] << endl;
                q.push(make_pair(next_x,next_y));
            }
        }
    }
}

int main(){
    int max=0;
    cin >> M >> N;
    
    queue< pair<int, int> > q;
    vector< vector<int> > tomato(N, vector<int>(M,0));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tomato[i][j];
            if(tomato[i][j]==1){ // 익은 토마토를 모두 큐에 넣음
                q.push(make_pair(i,j));
            }
        }
    }
    // BFS으로 탐색
    search(q,tomato);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tomato[i][j] == 0) {
                // 안 익은 토마토 하나라도 있으면 -1 출력 후 리턴
                cout << "-1" << endl;
                return 0;
            }
            // 모든 토마토 익는데 걸리는 시간 구하기 위해
            if(tomato[i][j] > max) max = tomato[i][j];
        }
    }
    // 처음 익은 토마토 인근 토마토의 익는 날짜가 1이 아닌 익은토마토(1)+1로 계산되었으므로 1을 빼줌
    cout << max-1 << endl;

    return 0;
}