#include <iostream>
#include <queue>
#define MAX_F 1000000
using namespace std;

class Sol{
public:
    int A[5];
    int stair[MAX_F+1];
    int visit[MAX_F+1];
    int dx[2];
    bool check=true;

    Sol(){
        // Initialize
        for(int i=0; i<5; i++) A[i]=0;
        // 1층부터 F층까지 초기화, 방문배열 초기화
        for(int i=1; i<=A[0]; i++) {
            stair[i]=0; 
            visit[i]=0;
        }
        // U,D 초기화
        dx[0]=0, dx[1]=0;
    }

    void search(){
        queue<int> q;
        q.push(A[1]);
        visit[A[1]]=1; // 이 부분도 방문표시 해줘야 함 따라서 1로 시작하고 최종값을 -1해주기

        while(!q.empty()){
            int cx=q.front();
            q.pop();
            if(cx==A[2]) {
                check=false;
                break;
            }            
            // U,D일 때 둘다 보기 때문에 cx 기준 U,D 방문수는 같아야 하므로 visit에 방문수 저장함
            for(int i=0; i<2; i++){
                int nx=cx + dx[i];
                // 유효하지 않거나 방문한적이 있다면 패스
                if(nx<=0 || nx>A[0] || visit[nx]!=0) continue;
                visit[nx]=visit[cx]+1;
                q.push(nx);
                cout << "current: " << nx << " visit: " << visit[nx] << "\n";                 
            }          
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Sol* sol = new Sol();
    // F(0), S(1), G(2), U(3), D(4)
    for(int i=0; i<5; i++) cin >> sol->A[i];
    // A[1]에서 A[2]로 가는 최단 거리?
    // 위: A[3], 아래: A[4]
    sol->dx[0]=sol->A[3];
    sol->dx[1]=-sol->A[4];

    // S>G인데 아래 버튼 없는 경우 
    if(sol->A[1]>sol->A[2] && sol->A[4]==0){
        cout << "use the stairs\n";
        return 0;
    }

    sol->search();
    if(sol->check==false){
        cout << sol->visit[sol->A[2]]-1 << "\n";
    }else{
        cout << "use the stairs\n";
    }

    return 0;
}