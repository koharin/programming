#include <iostream>
#include <vector>

using namespace std;

int dx[]={0,0,0,-1,1};
int dy[]={0,1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N,M,x,y,K;
    cin >> N >> M >> x >> y >> K;
    vector< vector<int> > v(N, vector<int>(M,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> v[i][j];
    }
    int cur_x=x, cur_y=y;
    
    // 주사위 초기화
    int dice[6]={0,}; // 위, 아래, 동, 서 , 북, 남
    vector<int> command(K);
    for(int i=0; i<K; i++) cin >> command[i];
    for(int i=0; i<K; i++){
        // 현재 지도에서 위치
        int n_x=cur_x+dx[command[i]];
        int n_y=cur_y+dy[command[i]];
        
        if(n_x<0 || n_y<0 || n_x>=N || n_y>=M) continue;
        int temp=dice[0];
        // 주사위 이동
        switch(command[i]){
            case 1: // 동으로 이동
            //cout << "command 1" << endl;
                
                dice[0]=dice[3];//위->서값
                dice[3]=dice[1];//서->바닥값
                dice[1]=dice[2];//바닥->동값
                dice[2]=temp;//동->위값
                
                // 북,남 변화 없음
            break;
            case 2: // 서로 이동
                //cout << "command 2" << endl;
                
                dice[0]=dice[2];//위->동값
                dice[2]=dice[1];//동->바닥값
                dice[1]=dice[3];//바닥->서값
                dice[3]=temp;//서->위값
                // 북,남 변화 없음
            break;
            case 3: // 북으로 이동
                //cout << "command 3" << endl;
                
                dice[0]=dice[5]; // 위->남값 
                dice[5]=dice[1]; // 남->바닥값
                dice[1]=dice[4]; // 바닥->북값
                dice[4]=temp; // 북->위값
                //동,서 변화 없음                
            break;
            case 4: // 남으로 이동
                //cout << "command 4" << endl;
                // 동,서 변화 없음
                
                dice[0]=dice[4]; //위->북값
                dice[4]=dice[1];//북->바닥값
                dice[1]=dice[5]; // 바닥->남값
                dice[5]=temp; // 남->위값
            break;
        }
        // 이동한 칸에 쓰여 있는 수가 0이면
        if(v[n_x][n_y]==0) v[n_x][n_y]=dice[1]; // 바닥에 써있는 값 지도에 복사
        else {
            dice[1]=v[n_x][n_y]; // 주사위 바닥에 현재 좌표에서의 값 적기
            v[n_x][n_y]=0; // 현재 좌표의 값은 0으로 
        }
        // 이동한 좌표로 현재 좌표 업데이트
        cur_x=n_x;
        cur_y=n_y;
        cout << dice[0] << endl; // 주사위 윗 면에 쓰여 있는 수 출력
    }
    return 0;
}