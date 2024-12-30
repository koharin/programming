#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; // n: 일의 양
    cin >> n;
    // nxn initialize with 0
    vector< vector<int> > map(n, vector<int>(n,0));
    
    // 업무 간 상성 Pij
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> map[i][j];
    }

    
    return 0;
}