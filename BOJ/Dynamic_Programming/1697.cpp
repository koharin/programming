#include <iostream>
#include <queue>

using namespace std;
// 걷는 경우 1초 후 X-1 또는 X+1 위치
// 순간이동 1초 후 2*X 위치
int N,K;
int visit[100001]={0,};

void BFS(){
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        if(front==K) { 
            cout << visit[K] << endl;
            break;
        }
        if((front+1)>=0 && (front+1)<=100000 && visit[front+1]==0){
            visit[front+1]=visit[front]+1;
            q.push(front+1);
        }
        if((front-1)>=0 && (front-1)<=100000 && visit[front-1]==0){
            visit[front-1]=visit[front]+1;
            q.push(front-1);
        }
        if((2*front)>=0 && (2*front)<=100000 && visit[2*front]==0){
            visit[2*front]=visit[front]+1;
            q.push(2*front);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N >> K;
    
    BFS(); 
    
    return 0;
}