#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#define MAX_N 20
#define MAX_G 10
#define MAX_MATRIX 100

using namespace std;

int n;
// 길이 1인 정사각형 (i,j) 기준 (0,0) (0,1) (1,0) (1,1)이 모두 0이 아니어야 함
int rx[]={0,0,1,1};
int ry[]={0,1,0,1};
// 생성 방향 0: 왼쪽, 1: 위쪽 2: 오른쪽 3: 아래
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};

class Sols{
public:
    vector< tuple<int,int,int,int> > curves; // x,y,direction, g (오,위,왼,아래)
    int matrix[MAX_MATRIX][MAX_MATRIX];
    vector< pair< int, pair<int,int> > > vertexs[MAX_N+1];
    int max_row, max_col;

    Sols(){
        max_row=INT_MIN, max_col=INT_MIN;
        for(int i=0; i<MAX_MATRIX; i++){
            for(int j=0; j<MAX_MATRIX; j++) matrix[i][j]=0;
        }
    }
    void print(){
        for(int i=0; i<=max_row; i++){
            for(int j=0; j<=max_col; j++) cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
    // 0->1, 1->2, 2->3,3->4,  
    int turn_clock(int d){
        return (d+1)%4;
    }
    
    void solution(tuple<int,int,int,int> dragon, int num){
        int x,y,d,g;
        tie(x,y,d,g)=dragon;
        
        // 0차원
        matrix[x][y]=num; // dragon curve 번호 넣기
        vertexs[num].push_back(make_pair(d, make_pair(x,y)));
         
        matrix[x+dx[d]][y+dy[d]]=num;
        vertexs[num].push_back(make_pair(d, make_pair(x+dx[d],y+dy[d])));
        max_row=max(max_row, x+dx[d]);
        max_col=max(max_col,y+dy[d]);        
        
        // 1차원부터
        for(int i=1; i<=g; i++){ //1->1개 추가 2->1개 추가, 3->2개 추가 4->4개 추가
            // 1차원 만드는 경우 정점 1개로 만듬 
            int count=pow(2, i-1); // 만들어야 하는 점의 개수
            while(count){  
                // vertexs의 마지막 정점을 꺼냄
                int cd=vertexs[num][count--].first;
                int cx=vertexs[num].back().second.first;
                int cy=vertexs[num].back().second.second;
                // 다음 만들 정점
                cd=turn_clock(cd);
                int nx=cx+dx[cd];
                int ny=cy+dy[cd];
                //if(nx<0 || ny<0 || nx>=MAX_MATRIX || ny>=MAX_MATRIX) continue;
                // 마지막 추가한 정점이 끝점
                matrix[nx][ny]=num;
                vertexs[num].push_back(make_pair(cd, make_pair(nx,ny)));
                max_col=max(max_col, ny);
                max_row=max(max_row, nx);          
            }
            
            
        }
    }
    int calculate_square(){
        int sum=0;
        // 좌측상단 좌표 가능 범위 0~max_row-1
        for(int i=0; i<=max_row-1; i++){
            for(int j=0; j<=max_col-1; j++){
                bool state=true;
               for(int k=0; k<4; k++){
                    if(matrix[i+rx[k]][j+ry[k]]==0) { state=false;  break; }
               }
               // for문 하고 true 나오면 4개 이루어진것
               if(state) sum++;
            }
        }
        return sum;
    }

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    Sols* sol = new Sols();

    for(int i=0; i<n; i++){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        sol->curves.push_back(make_tuple(x,y,d,g));
    }
    for(int i=0; i<n; i++){
        sol->solution(sol->curves[i],i+1);
        //sol->print();
    }
    cout << sol->calculate_square() << "\n";
    return 0;
}

// 0차 드래곤 커브 길이 1인 선분
// 1차 드래곤 커브 = 0차 드래곤 커브 복제해서 끝점 기준으로 시계방향으로 90도 회전하여 연결한 것 끝점: 시작점으로부터 가장 멀리 떨어진 점
// n차 드래곤 커브 = n-1차 드래콘 커브 끝점에 n-1차 드래곤 커브 복제 후 시계 방향 90도 회전하여 연결한 도형
// direction 0: y 증가하는 방향, 1; x 감소하는 방향, 2: x 증가하는 방향. 3: y 증가하는 방향