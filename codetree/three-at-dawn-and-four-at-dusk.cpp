#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int n; 
int ans=INT_MAX;
vector< vector<int> > v(20, vector<int>(20,0));
int evening[20]={0,}; //저녁에 하는 여부 

// 아침과 저녁 차이 계산
int Cal(){
    int morn=0, even=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //아침인 경우
            if(evening[i]==0 && evening[j]==0)
                morn+=v[i][j];
            //저녁인 경우
            if(evening[i]==1 && evening[j]==1) even+=v[i][j];
        }
    }
    return abs(morn-even);
}

void select(int index, int count){
    // n/2개 선택됐다면
    if(count== n/2){
        // 선택된 조합의 합 차이 계산하고 최솟값 찾음
        ans=min(ans,Cal());
        return;
    }
    //최종이 n/2가 안된다면
    if(index==n) return;

    // index번째를 아침에 하는 경우
    select(index+1, count);

    // index번째를 저녁에 하는 경우
    evening[index]=1;
    select(index+1,count+1); // 저녁을 선택하므로 count++
    evening[index]=0;//선택 끝난 후 다시 원래대로

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int count=0;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> v[i][j];
    select(0,0);
    cout << ans << endl;
    return 0;
}
//n개 중 저녁에 해당하는 일 n/2 뽑는 조합을 모두 만든다. => Backtracking (N개 중 M개 뽑는 조합) M=N/2인 경우
//현재 위치에서 0(선택X),1(선택O)