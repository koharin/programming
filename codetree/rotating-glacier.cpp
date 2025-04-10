#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#define MAX_NUM 64 // 격자 최대 크기 pow(2,6)
#define MAX_Q 1000
#define LIMIT 3

using namespace std;

int n,q;
int matrix_size;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

class Sols{
public:
    int matrix[MAX_NUM][MAX_NUM];
    bool visited[MAX_NUM][MAX_NUM];

    Sols(){
        
        for(int i=0; i<matrix_size; i++){
            for(int j=0; j<matrix_size; j++) {
                matrix[i][j]=0;
                visited[i][j]=false;
            }
        }
    }

    void print(){
        for(int i=0; i<matrix_size; i++){
            for(int j=0; j<matrix_size; j++) cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    /*
    @param L : 회전 레벨
    */
    void rotate(int square_size, int one_size){
        // 좌측상단 빙하 범위 선택해서 회전 시 다른 상하좌우 인접 격자도 회전함
        // 회전 레벨 1이면 2*2 격자 선택해서 1*1 잘라서 4등분으로 회전
        // 2면 4*4 격자 선택해서 2*2 크기로 4개 회전
        int temp[MAX_NUM][MAX_NUM];
        for(int i=0; i<matrix_size; i++){
            for(int j=0; j<matrix_size; j++) temp[i][j]=matrix[i][j];
        }
        for(int x1=0; x1<=matrix_size-square_size; x1+=square_size){
            for(int y1=0; y1<=matrix_size-square_size; y1+=square_size){
                // 좌측상단 x1,y1 기준 돌리기
                for(int x2=x1; x2<x1+square_size; x2+=one_size){
                    for(int y2=y1; y2<y1+square_size; y2+=one_size){
                        // 4등분했을 떄 좌측상단 x1,y1
                        int ox=x2-x1, oy=y2-y1;
                        int rx=oy, ry=square_size-one_size-ox;
                        //temp[rx+x1+0][ry+y1+0]=matrix[x2+0][y2+0]; // 일단 좌측상단만 옮기고
                        // 좌측상단(0,0)이고 이를 포함하느 one_size 크기가 있을 때 순차적으로 next에 원래 값 채우기
                        for(int i=0; i<0+one_size; i++){
                            for(int j=0; j<0+one_size; j++) temp[rx+x1+i][ry+y1+j]=matrix[x2+i][y2+j];
                        }
                        
                    }
                }
            }
        }
        //좌측상단 기준으로 one_size에 포함되는 값들을 
        // 원본에 복사
        for(int x1=0; x1<=matrix_size-square_size; x1+=square_size){
            for(int y1=0; y1<=matrix_size-square_size; y1+=square_size){
                // 좌측상단 x1,y1 기준 돌리기
                for(int x2=x1; x2<x1+square_size; x2++){
                    for(int y2=y1; y2<y1+square_size; y2++){                       
                        matrix[x2][y2]=temp[x2][y2];
                    }
                }
            }
        }        
    }

    void melt(){
        queue< pair<int,int> > q;
        q.push(make_pair(0,0));
        //visited[x][y]=true;
        int step[MAX_NUM][MAX_NUM];
        for(int i=0; i<matrix_size; i++){
            for(int j=0; j<matrix_size; j++) step[i][j]=0;
        }
        // 각 칸에 대해 인접한 얼음칸수 구하기
        for(int i=0; i<matrix_size; i++){
            for(int j=0; j<matrix_size; j++){
                // 얼음 없는 칸은 구하지 않음
                if(matrix[i][j]==0) continue;
                for(int d=0; d<4; d++){
                    int nx=i+dx[d];
                    int ny=j+dy[d];
                    if(nx>=0 && ny>=0 && nx<matrix_size && ny<matrix_size && matrix[nx][ny]!=0) step[i][j]++; // 인접 칸 얼음 수 구하기
                }                
            }
        } 
        // 녹이기?
        for(int i=0; i<matrix_size; i++){
            for(int j=0; j<matrix_size; j++){
                // 인접 칸 얼음이 3개 미만인 경우 
                if(matrix[i][j]==0) continue;
                if(step[i][j]<LIMIT) matrix[i][j]--;
            }
        }
    }

    int remain_glaciers(){
        int sum=0;
        // 남아있는 빙하의 총 양
        for(int i=0; i<matrix_size; i++){
            for(int j=0; j<matrix_size; j++) sum+=matrix[i][j];
        }
        return sum;
        // 가장 큰 크기 
    }

    int max_glaciers(int x, int y){
        int sum=1;
        visited[x][y]=true;
        queue< pair<int,int> > q;
        q.push(make_pair(x,y));

        while(!q.empty()){
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx=cx+dx[i];
                int ny=cy+dy[i];
                if(nx<0 || ny<0 || nx>=matrix_size || ny>=matrix_size || visited[nx][ny]==true || matrix[nx][ny]==0) continue;
                visited[nx][ny]=true;
                sum++;
                q.push(make_pair(nx,ny));
            }
        }
        return sum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Sols* sol=new Sols();
    int max_size=INT_MIN;

    cin >> n >> q;
    matrix_size=pow(2,n);

    for(int i=0; i<matrix_size; i++){
        for(int j=0; j<matrix_size; j++) cin >> sol->matrix[i][j];
    }

    for(int i=0; i<q; i++){
        int L; cin >> L;
        // L이면 square_size는 pow(2,L) 4등분 묶어서
        // Step 1. 회전
        int square_size=pow(2,L);
        int one_size=pow(2,L-1);
        // 회전 레벨 0은 얼음 위치 변하지 않음
        if(L!=0) sol->rotate(square_size, one_size);
        sol->print();
        // Step 2. 얼음 녹음
        for(int i=0; i<matrix_size; i++){
            for(int j=0; j<matrix_size; j++) sol->visited[i][j]=false;
        }
        sol->melt();
        sol->print();
    }
    cout << sol->remain_glaciers() << "\n";
    for(int i=0; i<matrix_size; i++){
        for(int j=0; j<matrix_size; j++){
            if(sol->matrix[i][j]!=0 && sol->visited[i][j]==false) {
                max_size=max(max_size, sol->max_glaciers(i,j));
            }
        }
    }
    if(max_size==INT_MIN) cout << 0 << "\n";
    else cout << max_size << "\n";
    return 0;
}
