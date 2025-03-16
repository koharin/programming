#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); // 두 표준 입력 동기화 해제
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int room=1;
    int i=1;
    while(N>i){
        i+=room*6;
        room++;
    }
    cout << room << endl;
    return 0;
}
// 방 1: 1개 (1)
// 방 2: 6개 (2-7)
// 방 3: 12개 (8-19)
// i%6 1