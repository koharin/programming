#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#define N_L 5
#define N_S 3

using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
queue<int> ruins;

class Sols{
public:
    int map[N_L][N_L];
    int visit[N_L][N_L];

    Sols(){
        // 초기화
        for(int i=0; i<N_L; i++){
            for(int j=0; j<N_L; j++) map[i][j]=0;
        }       
    }

    void print(){
        for(int i=0; i<N_L; i++){
            for(int j=0; j<N_L; j++) cout << map[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    // bfs 활용한 Flood Fill (다차원 배열의 어떤 칸과 연결된 영역을 찾는 알고리즘)
    int bfs(int x, int y){
        vector< pair<int,int> > trace;
        queue< pair<int,int> > q;
        q.push(make_pair(x,y));
        int value=map[x][y];
        trace.push_back(make_pair(x,y));
        visit[x][y]=1;

        while(!q.empty()){
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx=cx+dx[i];
                int ny=cy+dy[i];
                if(nx<0 || ny<0 || nx>=N_L || ny>=N_L || visit[nx][ny]==1 || map[nx][ny]!=value) continue;
                visit[nx][ny]=1;
                trace.push_back(make_pair(nx,ny));
                q.push(make_pair(nx,ny));
            }
        }
        if(trace.size()>=3) {
            // 유물 없애기 (없애기 위해 vector에 저장함)
            for(int i=0; i<trace.size(); i++){
                map[trace[i].first][trace[i].second]=0;
            }
        }
        return trace.size();

    }

    Sols* step1(int x, int y, int round){
        Sols* result = new Sols();
        // 회전 각도만큼 90도로 회전
        // (x,y)      (x,y+1),   (x,y+2)
        // (x+1,y)              (x+1,y+2)
        // (x+2,y) (x+2, y+1), (x+2, y+2)
        for(int i=0; i<N_L; i++){
            for(int j=0; j<N_L; j++) result->map[i][j]=map[i][j];
        }
        for(int i=0; i<round; i++){
            // 회전 중심 제외 8개 회전함
            int temp=result->map[x][y];
            result->map[x][y]=result->map[x+2][y];
            result->map[x+2][y]=result->map[x+2][y+2];
            result->map[x+2][y+2]=result->map[x][y+2];
            result->map[x][y+2]=temp; //map[x][y]
            temp=result->map[x+1][y+2];
            result->map[x+1][y+2]=result->map[x][y+1];
            result->map[x][y+1]=result->map[x+1][y];
            result->map[x+1][y]=result->map[x+2][y+1];
            result->map[x+2][y+1]=temp; // map[x+1][y+2]
        }
        
        return result;
    }
    int step2(){
        //print();
        // visit 초기화
        for(int i=0; i<N_L; i++){
            for(int j=0; j<N_L; j++) visit[i][j]=0;
        }         
        int sum=0;
        // Step 2. 유물 1차 획득 (유물 가치 = 모인 조각 개수)
        for(int i=0; i<N_L; i++){
            for(int j=0; j<N_L; j++){
                // 3개 이상일 때만 리턴
                if(visit[i][j]==0){
                    int count=bfs(i,j);
                    if(count>=3) sum+=count;
                }
            }
        }
        //cout << sum << endl;
        //      
        return sum;  
    }

    void Fill(){
        // ruins 처음부터 빈 칸 채움
        for(int j=0; j<N_L; j++){ // 행 큰 순으로
            for(int i=N_L-1; i>=0; i--){ // 열 작은 순으로
                if(map[i][j]==0){ // 빈 칸이면 ruins에서 꺼내서 채움
                    map[i][j]=ruins.front();
                    ruins.pop();
                }
            }
        }
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Sols* sol= new Sols();
    int K,M; 

    // Inputs
    cin >> K >> M;
    
    for(int i=0; i<N_L; i++){
        for(int j=0; j<N_L; j++) cin >> sol->map[i][j];
    }
    for(int i=0; i<M; i++){
        int ruin; cin >> ruin;
        ruins.push(ruin);
    }
    // Solution
    while(K--){
        Sols* max_sol=NULL;
        int max_value=0;        
        // Step 1. 탐사 진행
        // 격자 선택
        // 해당 좌측상단에서 90도, 180도, 270도 회전했을 때 작은 방법 선택
        // 좌측상단은 y는 0~2, x는 0~2까지 가능
        for(int t=1; t<=3; t++){
            // 여러가지면 회전 중심 열이 가장 작을 때, 열이 같으면 행이 가장 작을 때 선택
            for(int y=0; y<=2; y++){
                for(int x=0; x<=2; x++){
                    Sols* temp=sol->step1(x,y,t);
                    
                    int curr_value=temp->step2();
                    if(curr_value>max_value){
                        max_value=curr_value;
                        max_sol=temp;
                    }
                }
            }
        }
        // max_sol과 max_value 없으면 해당 턴 종료
        if(max_sol==NULL) break;
        // max_sol로 업데이트
        sol=max_sol;
        
        // 유물 연쇄 획득
        while(true){
            // 먼저 처음 유물 획득 때 채우고 연쇄 획득해야 하므로 fill먼저 진행
            sol->Fill();
            int value=0;
            value=sol->step2();
            if(value==0) break; // 3개 이상 모일 수 있는게 없으면 멈춤
            max_value+=value;
        }
        //sol->print();
        cout << max_value << " ";
    }
    return 0;
}