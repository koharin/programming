#include <iostream>

using namespace std;

int main(){
    int H,W,N,M;
    cin >> H >> W >> N >> M;
    int answer=0;

    for(int i=0; i<H; i=i+N+1){
        for(int j=0; j<W; j=j+M+1){
            answer++;

        }
    }
    cout << answer << endl;
    return 0;
}