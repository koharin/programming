#include <iostream>
#include <vector>
#define MAX_T 1000
#define MAX_NUM 50

using namespace std;

int dx[]={-1,1,0,0,};
int dy[]={0,0,-1,1};
int n,m,t;
int room[MAX_NUM][MAX_NUM];
int diff[MAX_NUM][MAX_NUM];
int visit[MAX_NUM][MAX_NUM];
vector< pair<int,int> > storm; // 항상 두 칸 차지함

void Input(){
    cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> room[i][j];
            if(room[i][j]==-1) storm.push_back(make_pair(i,j));
        }
    }
}
void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cout << room[i][j] << " ";
        }
        cout << endl;
    }    
    cout << endl;
}
void diffusion(){
    // diffusion 배열 초기화 (각 칸에 확산되는 양)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            diff[i][j]=0;
        }
    }
    // 각 칸의 먼지가 인접 4방향으로 확산됨
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(room[i][j]==-1) continue;
            int current=room[i][j];
            int amount=current/5;
            int count=0;
            for(int d=0; d<4; d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                // 시공의 돌풍 있거나, 범위 벗어나면 확산되지 않음
                if(nx<0 || ny<0 || nx>=n || ny>=m || room[nx][ny]==-1) continue;
                diff[nx][ny]+=amount;
                count++;
            }
            room[i][j]=current-amount*count; // 확산된 개수만큼 뺌
        }
    }
    // 원래 칸 먼지=원래 먼지 양-확산된 먼지 양
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            room[i][j]+=diff[i][j];
        }
    }
}
void clean(){
    pair<int,int> up=storm.front();
    pair<int,int> down=storm.back();
    // 반시계 방향 바람
    int temp_right_down=room[up.first][m-1]; // (up.first,m-1)
    //int temp_right_up=room[0][m-1]; // (0,m-1)
    int temp_left_up=room[0][0]; // (0,0)
    // 아래칸    
    for(int i=m-1; i>=up.second+2; i--) room[up.first][i]=room[up.first][i-1];
    room[up.first][up.second+1]=0;
    // 윗 칸
    for(int i=0; i<m-1; i++) room[0][i]=room[0][i+1];
    // 오른쪽 side
    for(int i=0; i<up.first-1; i++) room[i][m-1]=room[i+1][m-1];
    room[up.first-1][m-1]=temp_right_down;
    //cout << temp_right_down << endl;
    // 왼쪽 side
    for(int i=up.first-1; i>1; i--) room[i][0]=room[i-1][0];
    room[1][0]=temp_left_up;

    // 시계 방향 바람
    int temp_right_up=room[down.first][m-1];
    temp_right_down=room[n-1][m-1];
    int temp_left_down=room[n-1][0];    
    // 윗 칸
    for(int i=m-1; i>=down.second+2; i--) room[down.first][i]=room[down.first][i-1];
    room[down.first][down.second+1]=0;
    // 아랫칸
    for(int i=0; i<m-1; i++) room[n-1][i]=room[n-1][i+1];
    // 오른쪽 side
    for(int i=n-1; i>down.first+1; i--) room[i][m-1]=room[i-1][m-1];
    room[down.first+1][m-1]=temp_right_up;
    // 왼쪽 side
    for(int i=down.first+1; i<n-2; i++) room[i][0]=room[i+1][0];
    room[n-2][0]=temp_left_down;
}
int calculate_dust(){
    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //if(room[i][j]==-1) continue;
            sum+=room[i][j];
        }
    }
    return sum;
}
void solution(){
    // Step 1. 먼지의 확산
    diffusion();
    print();
    
    //Step 2. 시동의 돌풍의 청소
    // 시공의 돌풍 윗칸은 반시계 방향으로 바람 일으킴
    // 시공의 돌품 아랫칸은 시계 방향으로 바람 일으킴
    // 바람 불면 먼지가 바람 방향대로 모두 한칸씩 이동
    // 시공의 돌풍으로 들어간 먼지는 사라짐(바로 윗칸과 바로 아랫칸.바로 옆은 0으로 바뀜)
    clean();
    print();
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Input();
    int ans=0;
    for(int i=0; i<t; i++){
        solution();
        ans=calculate_dust();
    }
    cout << ans+2 << "\n";
    return 0;
}