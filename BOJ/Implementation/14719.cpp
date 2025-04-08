#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    int H,W;
    cin >> H >> W;
    int count=0;
    vector<int> v(W);
    for(int i=0; i<W; i++){
        cin >> v[i];
    }

    for(int i=1; i<W; i++){
        int left=0, right=0;
        // i 기준 왼쪽에서 최댓값 구하기
        for(int j=0; j<i; j++) left=max(left, v[j]);
        // i 기준 오른쪽에서 최대값 구하기
        for(int j=i+1; j<W; j++) right=max(right, v[j]);
        count+=max(0, min(left,right)-v[i]); // 현재 빗물은 높은거-낮은거-현재 높이임
        // max 하는 이유는 만약 오른쪽이나 왼쪽에 큰게 아예 없어서 v에서 빼면 - 나올 수 있으므로 0으로 만ㄷ들어줌
        //cout << count << endl;
    }
    cout << count << "\n";
    return 0;
}