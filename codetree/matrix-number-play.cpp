#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_NUM 100
#define MAX_M 3
using namespace std;
// 숫자 최대 100이므로 아무것도 겹치지 않을 때 크기는 200
int r,c,k;
int matrix[2*MAX_NUM+1][2*MAX_NUM+1];
int rows=3,cols=3;

void Input(){
    cin >> r >> c >> k;
    
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=cols; j++) cin >> matrix[i][j];
    }
}

int cal_rows(int row){
    // 행에 대해 출현 빈도 수 계산
    vector< pair<int,int> > p;
    for(int i=1; i<=MAX_NUM; i++){
        int frequency=0;
        for(int j=1; j<=cols; j++){
            if(matrix[row][j]==i){
                frequency++;
            }
        }
        if(frequency) p.push_back(make_pair(frequency,i));
    }
    // 숫자 새로 적기 위해 해당 row 행 모두 0으로 바꿈
    for(int i=1; i<=cols; i++) matrix[row][i]=0;
    
    // 출현 빈도 수  적은 순서대로 정렬
    sort(p.begin(), p.end());
    for(int i=0; i<p.size(); i++){
        matrix[row][i*2+1]=p[i].second; // number
        matrix[row][i*2+2]=p[i].first; // frequency
    }

    return (int)p.size()*2;
}

int cal_cols(int col){
    // col 열에 대해 num의 출현 빈도 계산
    vector< pair<int,int> > p; // {frequency, num}
    
    for(int i=1; i<=MAX_NUM; i++) // 숫자 100까지이므로
    {
        int frequency=0;
        for(int row=1; row<=rows; row++){
            if(matrix[row][col]==i){
                frequency++;
            }
        }
        if(frequency) p.push_back(make_pair(frequency,i));
    }
    // 정렬
    sort(p.begin(), p.end());
    // matrix row 1~MAX_NUM에서 col일 때 열을 0으로 초기화
    for(int i=1; i<=MAX_NUM; i++){
        matrix[i][col]=0;
    }
    // sort된 걸 0부터 넣음
    for(int i=0; i<p.size(); i++){
        matrix[i*2+1][col]=p[i].second; // num
        matrix[i*2+2][col]=p[i].first; // frequency
    }
    // 최종 해당 열의 길이는 (num,frequency)가 묶여있으므로 p.size()*2
    return (int)p.size()*2;
}

void solution(){
    if(rows>=cols){
        int max_cols=0;
        // 각 행 업데이트
        for(int i=1; i<=rows; i++)
            max_cols = max(max_cols, cal_rows(i)); // 각 행에서 반환되는 열 길이가 긴걸로 업데이트
        cols=max_cols;
    }else{
        int max_row=0;
        // 열 업데이트  
        for(int i=1; i<=cols; i++)
            max_row=max(max_row, cal_cols(i));
        rows=max_row;
    }
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=cols; j++) cout << matrix[i][j];
        cout << endl;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int ans=-1;

    Input();
    
    // 100초 동안 시뮬레이션 진행
    for(int t=0; t<=100; t++){
        if(matrix[r][c]==k) {
            ans=t;
            break;
        }
        solution();
    }
    cout << ans << "\n";

    return 0;
}