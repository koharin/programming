#include <iostream>
#include <vector>
#include <tuple>
#define MAX_N 12
#define MAX_K 10
#define WHITE 0
#define RED 1
#define BLUE 2

using namespace std;
// WHITE 0 RED 1 BLUE 2
int N,K;
int dx[]={0,0,0,-1,1};
int dy[]={0,1,-1,0,0};

class Sols{
public:
    int matrix[MAX_N+1][MAX_N+1];
    vector< tuple<int,int,int> > hourse[MAX_N+1][MAX_N+1]; // {x,y,d,status}
    vector< tuple<int,int,int> > moved_hourse[MAX_N+1][MAX_N+1];
    vector< tuple<int,int,int> > pos;

    Sols(){
        pos.resize(N);
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) {
                matrix[i][j]=0;
            }
        }
    }
    void print(){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(hourse[i][j].size()==0) continue;
                cout << i << "," << j << endl;
                for(auto& [x,y, d] : hourse[i][j]) cout << d << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // →, ←, ↑, ↓
    int reverse_dir(int d){
        switch(d){
            case 1:
                return 2;
            case 2:
                return 1;
            case 3:
                return 4;
            case 4:
                return 3;
        }
    }
    void move(int num){
        // 가장 아래의 말의 d에 따라 이동
        int dir;
        
        auto& [cur_x, cur_y, cur_d] = pos[num];
        if(hourse[cur_x][cur_y].size()!=0){
            // 현재가 가장 아래가 아닐 수 있으므로 가장 아래의 dir을 가져옴
            tie(ignore,ignore,dir)=hourse[cur_x][cur_y].front();
            
        }else dir=cur_d;
        
        int nx=cur_x+dx[dir];
        int ny=cur_y+dy[dir];
        int value;
        if(nx<=0 || ny<=0 || nx>N || ny>N || matrix[nx][ny]==BLUE){
            cur_d=reverse_dir(cur_d);
            nx=cur_x+dx[cur_d];
            ny=cur_y+dy[cur_d];
            // 그래도 유효하지 않거나 파란색이면
            if(nx<=0 || ny<=0 || nx>N || ny>N || matrix[nx][ny]==BLUE){
                value=BLUE;
            } else value=matrix[nx][ny];            
        }
        else value=matrix[nx][ny];
 
       
        switch(value){
            case WHITE:
            {
                // 먼저 기존에 있던거 넣음
                for(int i=0; i< hourse[nx][ny].size(); i++) moved_hourse[nx][ny].push_back(hourse[nx][ny][i]);
                // cur_x cur_y 위치에 있던 애들을 맨 위에 차례로 넣음
                for(int i=0; i<hourse[cur_x][cur_y].size(); i++){
                    auto& [x,y,d]=hourse[cur_x][cur_y][i];
                    moved_hourse[nx][ny].push_back(make_tuple(nx,ny,d));
                }
                cur_x=nx;
                cur_y=ny;                
            }
            break;
            case RED:
            {
                // 먼저 기존에 있던거 넣음
                for(int i=0; i< hourse[nx][ny].size(); i++) moved_hourse[nx][ny].push_back(hourse[nx][ny][i]);
                // cur_x cur_y 위치에 있던 애들을 순서 반대로 넣음
                for(int i=hourse[cur_x][cur_y].size()-1; i>=0; i--){
                    auto& [x,y,d]=hourse[cur_x][cur_y][i];
                    moved_hourse[nx][ny].push_back(make_tuple(nx,ny,d));
                }
                cur_x=nx;
                cur_y=ny;                 
            }
            break;
            case BLUE:
            {
                // 원래 자리에 있는거 그대로 복사하기
                for(int i=0; i<hourse[cur_x][cur_y].size(); i++){
                    moved_hourse[cur_x][cur_y].push_back(hourse[cur_x][cur_y][i]);
                }
            }
            break;
        }
        // 원본 초기화
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) hourse[i][j].clear();
        }
        // 원본에 복사
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                for(tuple<int,int,int> tp: moved_hourse[i][j]) hourse[i][j].push_back(tp);
            }
        }        

    }

    bool calc_hourses(){
        bool check=false;

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                int count=0;
                if(hourse[i][j].size()>=4){ check=true; break; }
            }
        }
        return check;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Sols* sol=new Sols();

    cin >> N >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cin >> sol->matrix[i][j];
    }
    for(int i=0; i<K; i++){
        int x,y,d;
        cin >> x >> y >> d;
        sol->hourse[x][y].push_back(make_tuple(x,y,d));
        sol->pos.push_back(make_tuple(x,y,d));
    }
    int k;
    bool end=false;
    for(k=1; k<=1000; k++){

        if(sol->calc_hourses()) { end=true; break; }
        // 초기화
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++) sol->moved_hourse[i][j].clear();
        }
        for(int i=0; i<sol->pos.size(); i++){
            sol->move(i);
        }
        sol->print();
        break;
    }
    if(k==1000 && end==false) cout << "-1\n";
    else cout << k << "\n";

    return 0;
}