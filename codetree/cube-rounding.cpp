#include <iostream>
#include <vector>
using namespace std; 

vector<int> dice(6,0); // 위(0), 아래(1),동(2), 서(3), 북(4), 남(5)
int n,m,x,y,k;
int graph[20][20]={0,};
int dx[]={0,0,0,-1,1}; // 동(1), 서(2), 북(3), 남(4)
int dy[]={0,1,-1,0,0}; // 동(1), 서(2), 북(3), 남(4)
void move(int direction){
    int temp=dice[0];
    switch(direction){
        case 1: // 동으로 이동
        dice[0]=dice[3]; //위->서값
        dice[3]=dice[1];//서->바닥값
        dice[1]=dice[2];//바닥->동값
        dice[2]=temp; //동->위값
        break;
        case 2: //서로 이동
        dice[0]=dice[2]; //위->동값
        dice[2]=dice[1]; //동->바닥값
        dice[1]=dice[3]; //바닥->서값
        dice[3]=temp; //서->위값
        break;
        case 3: // 북으로 이동
        dice[0]=dice[5];//위->남값
        dice[5]=dice[1];//남->바닥값
        dice[1]=dice[4];//바닥->북값
        dice[4]=temp;//북->위값
        break;
        case 4: // 남으로 이동
        dice[0]=dice[4];//위->북값
        dice[4]=dice[1];//북->바닥값
        dice[1]=dice[5];//바닥->남값
        dice[5]=temp;//남->위값
        break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y >> k;
    vector<int> dir(k,0);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> graph[i][j];
    for(int i=0; i<k; i++) cin >> dir[i];        
    for(int i=0; i<k; i++){
        //현재 바닥면
        int nx=x+dx[dir[i]];
        int ny=y+dy[dir[i]];
        if(nx<0 || ny<0 || nx>=n || ny>=m) continue; // 범위 벗어나는 경우 굴리지 않음
        // dice 돌리기
        move(dir[i]);
        // 칸에 쓰여져 있는 수가 0이면
        if(graph[nx][ny]==0) graph[nx][ny]=dice[1];
        else{
            dice[1]=graph[nx][ny];
            graph[nx][ny]=0;
        }
        x=nx; y=ny;
        // 정육면체 상단 면에 쓰인 숫자 출력
        cout << dice[0] << "\n";
    }
    return 0;
}
// 칸에 쓰여있는 수가 0인 경우: graph[i][j]=dice[1]
// 칸이 0이 아닌 경우 dice[1]=graph[i][j], graph[i][j]=0