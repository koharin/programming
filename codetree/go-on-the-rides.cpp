#include <iostream>
#include <tuple>
#include <cmath>

#define MAX_N 20
#define MAX_NUM 400 // 20*20

using namespace std;

int ride[MAX_N][MAX_N];
bool like[MAX_NUM+1][MAX_NUM+1];
int student[MAX_NUM+1];
int n;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

typedef tuple<int,int,int,int> Cell; // (좋아하는 학생 수, 빈 칸 수, -행 번호, -열 번호) 좋아하는 학생은 최대, 빈 칸 최대, 행 작은, 열 번호 작은 
// 행 1,2 비교할 때 1<2이므로 작은게 우선시 안되므로 -1 > -2로 -를 붙여서 넣음

bool isFriend(int curr_stu, int stu){
    return like[curr_stu][stu];
}
Cell calculate(int student, int x, int y){
    int friend_cnt=0,blank_cnt=0;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        // 빈칸이면
        if(ride[nx][ny]==0) blank_cnt++;
        else if(isFriend(student, ride[nx][ny])==true) friend_cnt++;
    }
    return make_tuple(friend_cnt,blank_cnt,-x,-y);
}

void move(int student){
    // 해당 학생의 가장 우선순위 높은 정보
    Cell best_cell=make_tuple(0,0,-n, -n);
    // 각 위치에서 우선순위를 구함
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 이미 탑승한 위치면 패스
            if(ride[i][j]!=0) continue;
            Cell curr=calculate(student,i,j);
            // 우선순위 더 큰 걸 현재 cell로 업데이트
            if(best_cell<curr) best_cell=curr;
        }
    }
    // 학생 탑승
    int cx,cy;
    tie(ignore, ignore, cx, cy) = best_cell;
    ride[-cx][-cy]=student;
}

// 학생들 점수 총 합 계산
int score(int student, int x, int y){
    int cnt=0;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        // 유효하지 않은 위치면 패스
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        // 내가 좋아하는 친구라면
        if(isFriend(student, ride[nx][ny])) cnt++;
    }
    // 해당 학생의 점수 반환
    return (int)pow(10, cnt-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i=0; i<n*n; i++){
        cin >> student[i+1];
        for(int j=0; j<4; j++){
            int friends; cin >> friends;
            like[student[i+1]][friends]=true;
        }
    }
/*    
    for(int i=1; i<=n*n; i++){
        cout << i << ": ";
        for(int j=1; j<=n*n; j++) cout << like[i][j]<< " ";
        cout << endl;
    }
*/    
    // 탑승 계산
    for(int i=1; i<=n*n; i++) {
        move(student[i]);
    }
    
/*    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << ride[i][j] << " ";
        cout << endl;
    }
*/    
    // 점수 계산
    
    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) sum+= score(ride[i][j],i,j);
    }
    cout << sum << "\n";
    return 0;
}