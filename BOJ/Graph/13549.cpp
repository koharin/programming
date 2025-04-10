// 우선순위 2*x > x+1, x-1
// BFS -> 모든 간선 가중치 동일 -> 이 문제는 가중치가 다름
// deque 사용해서 2*x할 수 있으면 앞에 넣고, x+1, x-1 할 수 있으면 뒤에 넣음
// 각 단계에서 2*x, x+1, x-1 구하고
#include <iostream>
#include <deque>
#include <queue>
#define MAX_NUM 100000
using namespace std;

bool visited[100001];

int search(int N, int K){
    deque< pair<int,int> > dq;
    //priority_queue< int, vector< pair<int,int> >, greater<int> > pq;
    dq.push_back(make_pair(N,0)); // 시작 넣음
    
    visited[N]=true; // 방문표시 
    // 시간은 deque가 아니라서 pos*2와 time을 매칭시켜서 넣어야 함

    while(!dq.empty()){
        int cur_pos=dq.front().first; // 현재 위치
        int time=dq.front().second;
        dq.pop_front();

        if(cur_pos==K) {
            return time; // 처음에 0초인데 방문표시땜에 1로 시작했으므로
        }

        // 순간이동 가능한게 가장 위에 오도록 나중에 넣음
        if(cur_pos*2<=MAX_NUM && !visited[cur_pos*2]){
            dq.push_front(make_pair(cur_pos*2,time));
            visited[cur_pos*2]=true; // 시간 안걸림
            
        } 
        if(cur_pos-1>=0 && !visited[cur_pos-1]){
            dq.push_back(make_pair(cur_pos-1, time+1));
            visited[cur_pos-1]=true;
            
        }        
        if(cur_pos+1<=MAX_NUM && !visited[cur_pos+1]){
            dq.push_back(make_pair(cur_pos+1,time+1));
            visited[cur_pos+1]=true;
            
        }
       

    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N,K;
    cin >> N >> K;
    cout << search(N,K) << "\n";

    return 0;
}