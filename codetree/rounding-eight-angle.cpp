#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <cmath>
#define MAX_N 4
using namespace std;
// 0: 북쪽 지방, 1: 남쪽 지방
struct ROUND{
    int n;
    int d;
};
vector<ROUND> rounds; 
deque< deque<int> > d(MAX_N+1);
int k;
int rotate_dir[MAX_N+1]; // 의자별 회전 방향

void Input(){
    // 필각의자 입력
    d[0].push_back(0);//0은 사용 안함
    for(int i=1; i<=4; i++){
        string s; cin >> s;
        for(int j=0; j<s.size(); j++) {
            d[i].push_back(s[j]-'0');
        }
    }
    // 회전 횟수 입력
    cin >> k;
    // 회전시킬 팔각의자 번호 n, 방향 d 입력
    for(int i=0; i<k; i++){
        ROUND round;
        int n,d; cin >> n >> d;
        round.n=n; round.d=d;
        rounds.push_back(round);
    }
    /*
    for(int i=0; i<4; i++){
        for(int num: d[i]) cout << num << " ";
        cout << endl;
    } 
     */   
}
void print(){
    int cnt=0;
    for(int i=1; i<d.size(); i++){
        for(int j=0; j<8; j++) {
            if(j==0) {
                if(d[i][j]==1)cnt+=pow(2,i-1)*1;
                else cnt+=pow(2,i-1)*0;
            }
            //cout << d[i][j] << " ";
        }
        //cout << endl;
    }
    cout << cnt << endl;
}
void rounding(int num, int dir){
    if(dir==1){
        int current=d[num].back();
        d[num].pop_back();
        d[num].push_front(current);
    }else{
        int current=d[num].front();
        d[num].pop_front();
        d[num].push_back(current);
    }
}
/*
void solution(){
    for(int i=0; k; i++){
        // 회전 시 n번 의자를 d 방향으로 45도 한 칸 회전
        int num=rounds[i].n;
        int dir=rounds[i].d;
        // 회전 규측(d[i-1][2]와 d[i][6], d[i][2]와 d[i+1][6]이 출신 지역 다르면 인접 의자는 반대 방향 회전
        // 시계 방향
        //num, num-2, num+2는 같은 방향으로 회전
        // num-1, num+1은 같은 방향 회전
        for(int j=1; j<d.size()-1; j++){
            if(d[j][2]==d[j+1][6]){ 
                if(j!=num) continue;
                else rounding(j,dir); //현재가 num인 경우 해당만 돌림
            }else{
                if(num%2!=0){ // 홀수인 경우
                    if(j%2!=0) rounding(j,dir);
                    else rounding(j,-dir);
                }else{
                    if(j%2==0) rounding(j,dir);
                    else rounding(j,-dir);
                }
            }
        }
        print();
    }
}
*/
int flip(int dir){
    return (dir==1) ? -1 : 1;
}
void solution(){
    for(int i=0; i<k; i++){
       int num=rounds[i].n;
       int dir=rounds[i].d;
       // Step 1. 각 의자 회전 방향 구하기
        // 방향 초기화 (0)
        for(int j=1; j<=MAX_N; j++) rotate_dir[j]=0;
        // 회전 시작 위치 반드시 회전
        rotate_dir[num]=dir;
        // num 좌측 회전 방향 정하기
        for(int j=num-1; j>0; j--){
            if(d[j][2]!=d[j+1][6]){
                rotate_dir[j]=flip(rotate_dir[j+1]);
            }else break;
        }
        // 우측 의자 회전 방향 결정
        for(int j=num+1; j<=MAX_N; j++){
            if(d[j][6]!=d[j-1][2]){
                rotate_dir[j]=flip(rotate_dir[j-1]);
            }else break;
        }
        // Step 2. 의자 회전
        for(int j=1; j<=MAX_N; j++){
            if(rotate_dir[j]!=0) rounding(j,rotate_dir[j]);
        }
        //print();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    Input();
    solution();
    print();

    return 0;
}